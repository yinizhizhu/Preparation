#include <iostream> 
using namespace std;
int t[100], f[100][100];
int maxN(int a, int b) { return (a > b ? a : b); }
void solve(int n, int m) {
	int i, j, k, temp, maxt;
	for (i = 1; i <= n; i++) f[i][1] = f[i - 1][1] + t[i];
	for (j = 2; j <= m; j++)
		cout << i << endl;
		for (i = j; i <= n; i++) {
			for (k = 1, temp = INT_MAX; k < i; k++) {
				maxt = maxN(f[i][1] - f[k][1], f[k][j - 1]);
				if (temp > maxt) temp = maxt;
			}
			f[i][j] = temp;
			cout << "\t" << j << ": " << f[i][j] << endl;
		}
}
int main() {
	int i, n, m;
	cin >> n >> m;
	if ((n < m) || (n == 0)) {
		cout << 0 << endl;
		return 0;
	}
	for (i = 1; i <= n; i++) cin >> t[i];
	solve(n, m);
	cout << f[n][m] << endl;
	return 0;
}

/*
5 4
5 1 9 6 3

*/