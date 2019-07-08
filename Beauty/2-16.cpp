#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

const int INF = 9999999;
const int N = 8;
int p[N], pre[N], path[N], n;

void show() {
	cout << "Path: ";
	for (int i = 0; i <= n; i++)
		cout << path[i] << "\t";
	cout << endl;
	cout << "Pre: ";
	for (int i = 0; i <= n; i++)
		cout << pre[i] << "\t";
	cout << endl;
}

void search(int num) {
	int h = 0, t = n, mid = (h + t) >> 1;
	for (; h < t;mid=(h+t)>>1) {
		if (path[mid] == num) return;
		else if (path[mid] > num) t--;
		else h++;
	}
	path[mid] = num;
	show();
}

int lis() {
	int i, h = 0;
	if (N) {
		n = 0;
		path[0] = p[0];
		pre[0] = -1;

		for (i = 1; i < N; i++) {
			if (p[i] > path[n]) {
				n++;
				path[n] = p[i];
				pre[n] = h;
				h = i;
			}
			else
				search(p[i]);
		}
	}
	cout << path[n];
	for (i = n; i; i--)
		cout << "->" << p[pre[i]];
	cout << endl;
	return n+1;
}

//page 198
int main() {
	//for (int i = 0; i < N; i++)
	//	p[i] = (rand() % 30 + 1);
	int i = 0;
	n = 0;
	p[i++] = 1;
	p[i++] = -1;
	p[i++] = 2;
	p[i++] = -3;
	p[i++] = 4;
	p[i++] = -5;
	p[i++] = 6;
	p[i++] = -7;
	cout << lis() << endl;
	return 0;
}
