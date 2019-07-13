#include <iostream>
#include <vector>

using namespace std;

const int N = 10;
int visited[N], nxt[N];
int n, m;  // n - the number of the left node, m - the number of the right node
vector<vector<int> > con(N, vector<int>());

/*
7
1 1
1 2
2 2
2 3
3 1
3 2
3 3
*/

bool find(int x) {
	for (int i = 0; i < con[x].size(); i++) {
		if (!visited[i]) {
			visited[i] = 1;
			if (nxt[i] == -1 || find(nxt[i])) {
				nxt[i] = x;
				return true;
			}
		}
	}
	return false;
}

void match() {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		memset(visited, 0, sizeof(visited));
		if (find(i)) ans++;
	}
	cout << ans << endl;
	cout << "The matching results are:" << endl;
	for (int i = 0; i < n; i++)
		cout << "\t" << i << " - " << nxt[i] << endl;
}

int main() {
	int line, i, j, x, y;
	cin >> line;
	m = n = 4;
	memset(nxt, -1, sizeof(nxt));
	for (i = 0; i < line; i++) {
		cin >> x >> y;
		con[x-1].push_back(y-1);
	}
	match();
	return 0;
}
