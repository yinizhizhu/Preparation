#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

const int N = 5;
int s[N], t[N], p[N];

void show() {
	for (int i = 0; i < N; i++)
		cout << s[i] << "\t";
	cout << endl;
	for (int i = 0; i < N; i++)
		cout << t[i] << "\t";
	cout << endl;
}

int maxM() {
	int i, ans, tmp;
	show();
	cout << "Output" << endl;
	t[N - 1] = s[0] = 1;
	s[1] = p[0];
	t[N - 2] = p[N - 1];
	for (i = 2; i < N; i++) s[i] = s[i - 1] * p[i - 1];
	for (i = N - 3; i >= 0; i--) t[i] = t[i + 1] * p[i + 1];
	ans = s[0] * t[0];
	cout << ans << "\t";
	for (i = 0; i < N; i++) {
		tmp = s[i] * t[i];
		if (tmp > ans) ans = tmp;
		cout << tmp << "\t";
	}
	cout << endl;
	return ans;
}

int maxM2() {
	int pn = 0, nn = 0, zn = 0, ans = 1;
	int minP=999999, minN=-999999;
	for (int i = 0; i < N; i++) {
		if (p[i] == 0) zn++;
		else if (p[i] > 0) {
			ans *= p[i];
			pn++;
			if (p[i] < minP) minP = p[i];
		}
		else {
			ans *= p[i];
			nn++;
			if (p[i] > minN) minN = p[i];
		}
	}
	if (zn > 1) return 0;
	if (zn == 1) {
		if (nn % 2) return 0;
		return ans;
	}
	if (nn % 2) return ans / minN;
	return ans / minP;
}

//page 185
int main() {
	for (int i = 0; i < N; i++)
		p[i] = (rand() % 30 + 1);
	cout << maxM() << endl;
	cout << maxM2() << endl;
	return 0;
}
