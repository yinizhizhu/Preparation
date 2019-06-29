#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

const int upper = 999999;

int ans[5];
int visit[5] = { 0,1,1,1,1 };
int path[5] = { 0, 0, 0, 0, 0 }; // Record the path
int dist[5][5] = { 0, 10, upper, upper, 5,
	upper, 0, 1, upper, 2,
	upper, upper, 0, 4, upper,
	7, upper, 6, 0, upper,
	upper, 3, 9, 2, 0 };

int min(int a, int b) {
	return (a > b ? b : a);
}

void Dijkstra() {
	int i, j, step;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++)
			printf("\t%d", dist[i][j]);
		printf("\n");
	}
	for (i = 0; i < 5; i++) ans[i] = dist[0][i];
	for (step = 1; step < 5; step++) {
		int minT = upper, j = 0;
		for (i = 1; i < 5; i++)
			if (visit[i] && ans[i] < minT) {
				minT = ans[i];
				j = i;
			}
		visit[j] = 0;
		for (i = 1; i < 5; i++)
			if (visit[i] && dist[j][i] < upper) {
				ans[i] = min(ans[i], ans[j] + dist[j][i]);
				path[i] = j;
			}

		//printf("Ans:\t");
		//for (i = 0; i < 5; i++)
		//	printf("%d\t", ans[i]);
		//printf("\nVisit:\t");
		//for (i = 0; i < 5; i++)
		//	printf("%d\t", visit[i]);
		//printf("\n");
	}
	printf("Find path:\n");
	for (i = 0; i < 5; i++) {
		printf("%d->", i+1);
		for (j = path[i]; j > 0; j = path[j])
			printf("%d->", j + 1);
		printf("1\n");
	}
	printf("\n");
}

void show(int tmp[5][5]) {
	int i, j;
	for (i = 0; i < 5; i++) {
		printf("\t");
		for (j = 0; j < 5; j++)
			printf("%d\t", tmp[i][j]);
		printf("\n\n");
	}
}

void Floyd() {
	int i, j, k;
	for (k = 0; k < 5; k++) {
		for (i = 0;  i < 5; i++) {
			for (j = 0; j < 5; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
		printf("STEP %d:\n", k + 1);
		show(dist);
	}
}

struct edge {
	int x, y, cost;
	edge() : x(0), y(0), cost(0) {}
	edge(int i, int j, int c) : x(i), y(j), cost(c) {}
};

bool BellmanFord() {
	int i, j;
	vector<edge> es;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
			if (dist[i][j] < upper)
				es.push_back(edge(i, j, dist[i][j]));
	int ans[5];
	for (i = 1; i < 5; i++) ans[i] = upper;
	ans[0] = 0;
	for (j = es.size() - 1; j; j--)
		for (i = 0; i < es.size(); i++)
			ans[es[i].y] = min(ans[es[i].y], ans[es[i].x] + es[i].cost);

	cout << "Ans in Bellman Ford:\n";
	for (i = 0; i < 5; i++)
		cout << ans[i] << "\t";
	cout << endl;

	for (i = 0; i < es.size(); i++)		// Check Negative circle path
		if (ans[es[i].y] > ans[es[i].x] + es[i].cost) {
			cout << "There is a negative circle path" << endl;
			return false;
		}
	return true;
}

bool SPFA() {
	int i, j, h;
	int mark[5];
	queue<int> con;
	vector<vector<int> > es;
	for (i = 0; i < 5; i++) {
		mark[i] = 0;
		vector<int> tmp;
		for (j = 0; j < 5; j++)
			if (dist[i][j] < upper)
				tmp.push_back(j);
		es.push_back(tmp);
	}

	int ans[5];
	for (i = 1; i < 5; i++) ans[i] = upper;
	ans[0] = 0;
	mark[0] = 1;
	con.push(0);


	for (; !con.empty(); ) {
		h = con.front();
		mark[h] = 0;
		con.pop();
		for (i = 0; i < es[h].size(); i++) {
			j = es[h][i];
			if (ans[j] > ans[h] + dist[h][j]) {
				ans[j] = ans[h] + dist[h][j];
				if (mark[j] == 0) {
					con.push(j);
					mark[j] = 1;
				}
			}
		}
	}

	cout << "Ans in SPFA:\n";
	for (i = 0; i < 5; i++)
		cout << ans[i] << "\t";
	cout << endl;
	return true;
}

// 单源最短路径（V-节点数，E-边数）
//		Dijkstra: 贪心法，无法处理带负权重的图， O(V*V)
//		Bellman Ford：动态规划，可处理无负环的图（可以有负权的边），O(V*E)
//			其中每一次的松弛操作就以为这找到了新的最短路
//		SPFA：用队列优化的Bellman Ford算法，迭代次数应该是最短路径树的深度（以源点作为根节点）。
// 多源最短路径：Floyd，O(V*V*V)
int main() {
	Dijkstra();
	BellmanFord();
	SPFA();
	Floyd();
	return 0;
}