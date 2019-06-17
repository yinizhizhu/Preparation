#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int min(int a, int b) { return (a > b ? b : a); }

int cut(int n) {
	int p[11] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
	vector<int> ans(n + 1, -1);
	int i, j, r;
	r = min(ans.size(), 11);
	for (i = 0; i < r; i++)
		ans[i] = p[i];
	for (i = 3; i <= n; i++) {
		r = ans[i];
		for (j = 1; j < i; j++)
			r = max(r, ans[i - j] + ans[j]);
		ans[i] = r;
	}
	return ans[n];
}

int minPTime() {
	int p[5] = { 0, 1, 2, 5, 10 };
	int ans[5], i;
	for (i = 0; i < 3; i++) ans[i] = p[i];
	for (i = 3; i < 5; i++)
		ans[i] = min(ans[i - 1] + p[1] + p[i],
			ans[i-2] + p[1] + p[i] + 2*p[2]);
	return ans[4];
}

void showVector(vector<vector<int> >& con) {
	cout << "*** CON ***" << endl;
	int i, j, n = con.size();
	for (i = 0; i < n; i++) {
		for (j = 0; j < con[i].size(); j++)
			cout << con[i][j] << " ";
		cout << endl;
	}
}
int gap() {
	string str = "abbc";
	//string str = "abdldjflsajflwf";
	int n = str.size();
	vector<vector<int> > con(n, vector<int>(n, 0));
	showVector(con);
	int len, i, x, y;
	for (len = 1; len < n; len++) {
		for (i = 0; i < n - len; i++) {
			x = i, y = i + len;
			if (str[x] == str[y])
				con[x][y] = con[x + 1][y - 1];
			else
				con[x][y] = min(con[x + 1][y], con[x][y - 1]) + 1;
			cout << "x: " << x << ", y:" << y << ", con[x][y]: " << con[x][y] << endl;
			for (; x <= y; x++)
				cout << str[x];
			cout << endl;
			showVector(con);
		}
	}
	return con[0][n - 1];
}

int zeroone() {
	int c[5] = {0, 5, 1, 10, 2 };
	int v[5] = {0, 2, 4, 8, 4 };
	int n = 11;
	vector<vector<int> > f(5, vector<int>(n, 0));
	int i, j;
	for (i = 1; i < 5; i++) {
		for (j = 1; j < n; j++) {
			if (j >= c[i])
				f[i][j] = max(f[i - 1][j], f[i - 1][j - c[i]] + v[i]);
			else
				f[i][j] = f[i - 1][j];
		}
		showVector(f);
	}
	return f[4][10];
}

// From https://blog.csdn.net/u013309870/article/details/75193592

int main() {
	cout << cut(4) << endl;
	cout << minPTime() << endl;
	cout << gap() << endl;
	cout << zeroone() << endl;
	return 0;
}