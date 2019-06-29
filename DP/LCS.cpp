#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
	string str1 = "1AB2345CD", str2 = "12345EF";
	int n = str1.size(), m = str2.size(), i, j, ans = 0, end;
	vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (str1[i-1] == str2[j-1])
				dp[i][j] = dp[i - 1][j - 1] + 1, ans = max(dp[i][j], ans), end = j;
		}
	}
	cout << "\t\t";
	for (i = 0; i <= m; i++)
		cout << "\t" << str2[i];
	cout << endl;
	for (i = 0; i <= n; i++) {
		cout << "\t";
		if (i) cout << str1[i - 1];
		for (j = 0; j <= m; j++)
			cout << "\t" << dp[i][j];
		cout << endl;
	}
	cout << "ans: " << ans << endl;
	for (i = end - ans + 1; i <= end; i++)
		cout << str2[i-1];
	cout << endl;
	return 0;
}