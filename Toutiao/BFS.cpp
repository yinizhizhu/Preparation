#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct point {
	int x, y;
	point() : x(0), y(0) {}
	point(int a, int b) : x(a), y(b) {}
};

const int N = 99;
int con[N][N], m, n;
int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
bool visited[N][N];

void BFS(point p) {
	queue<point> Q;
	Q.push(p);
	for (; Q.size();) {
		int i = Q.size();
		for (; i; i--) {
			p = Q.front();
			int cur = con[p.x][p.y];
			for (int i = 0; i < 4; i++) {
				point tmp = p;
				tmp.x += dir[i][0];
				tmp.y += dir[i][1];
				if (tmp.x >= 1 && tmp.x < m - 1 && tmp.y >= 1 && tmp.y < n - 1) {
					if (visited[tmp.x][tmp.y] && cur < con[tmp.x][tmp.y]) {
						Q.push(tmp);
						visited[tmp.x][tmp.y] = false;
					}
				}
			}
			Q.pop();
		}
	}
}

void find() {
	for (int i = 0; i < m; i++) {
		BFS(point(i, 0));
		BFS(point(n - 1, i));
	}
	for (int i = 1; i < n - 1; i++) {
		BFS(point(0, i));
		BFS(point(m - 1, i));
	}
	for (int i = 1; i < m - 1; i++)
		for (int j = 1; j < n - 1; j++)
			if (visited[i][j])
				cout << i << ", " << j << ": " << con[i][j] << endl;
}

void show() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << "\t" << con[i][j];
		cout << endl;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << "\t" << visited[i][j];
		cout << endl;
	}
}

int main() {
	m = n = 9;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			con[i][j] = rand() % 100 + 1;
			visited[i][j] = true;
		}
	show();
	find();
	return 0;
}