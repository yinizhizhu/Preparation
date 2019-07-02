#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;
const int N = 10002;
const double INF = 11258999068426240000;
int r, c, n, direct[4] = {-1, 1, -1, 1};
bool mark[N];
queue<int> q;
double ans[N], cost[N], time, v;
void update(int j) {
	if (j >= 0 && j < n && ans[j] > time) {
		ans[j] = time;
		if (!mark[j]) {
			q.push(j);
			mark[j] = true;
		}
	}
}
int main() {
	int i, j, s, e;
	scanf("%lf%d%d%d", &v, &r, &c, &s);
	for (i = 1, n = r * c; i < n; i++) {
		scanf("%d", &e);
		cost[i] = pow(2.0, e - s) / v;
		ans[i] = INF;
		mark[i] = false;
	}
	q.push(0);
	ans[0] = 0;
	mark[0] = true;
	cost[0] = 1.0 / v;
	direct[2] = -c, direct[3] = c;
	for (; !q.empty(); ) {
		j = q.front();
		q.pop();
		mark[j] = false;
		time = cost[j] + ans[j];
		for (i = 0; i < 4; i++)
			update(j + direct[i]);
	}
	printf("%.2f", ans[n - 1]);
	return 0;
}
