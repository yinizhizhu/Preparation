#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

const int INF = 9999999;
const int N = 6;
int p[N], ans[N][N];

void show() {
	cout << "Ans:" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << "\t" << ans[i][j];
		cout << endl;
	}
	cout << endl;
}

int maxN() {
	int i, ans = -INF, tmp = 0, h = 0;
	int ansh = 0, anst = 0;
	for (i = 0; i < N; i++) {
		tmp += p[i];
		if (tmp < 0) {
			if (tmp > ans) {
				ans = tmp;
				ansh = i;
				anst = i;
			}
			h = -1;
			tmp = 0;
			continue;
		}
		else {
			if (h == -1) h = i;
			if (tmp > ans) {
				ans = tmp;
				ansh = h;
				anst = i;
			}
		}
	}
	cout << p[ansh] << "->" << p[anst] << endl;
	return ans;
}

//page 185
int main() {
	//for (int i = 0; i < N; i++)
	//	p[i] = (rand() % 30 + 1);
	int i = 0;
	p[i++] = -10;
	p[i++] = -2;
	p[i++] = -3;
	p[i++] = -5;
	p[i++] = -1;
	p[i++] = -22;
	cout << maxN() << endl;
	return 0;
}
