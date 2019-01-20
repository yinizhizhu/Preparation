#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

const int N = 3;

void show(vector<int>& con) {
	int i = 0, n = con.size();
	for (; i < n; i++)
		cout << con[i];
	cout << endl;
}

int main() {
	bool flag;
	int i, j, k, noupdate;
	vector<vector<int> > bigint;
	for (i = 0; i < N; i++)
		bigint.push_back(vector<int> ());
	bigint[1].push_back(0);
	for (i = 1, j = 10 % N;; i++, j = (j * 10) % N) {
		noupdate = 0;
		flag = false;
		if (bigint[j].size() == 0) {
			bigint[j].clear();
			bigint[j].push_back(i);
		}
		for (k = 1; k < N; k++) {
			if (bigint[k].size() > 0 && i > bigint[k][bigint[k].size() - 1]
				&& bigint[(k + j) % N].size() == 0) {
				flag = true;
				bigint[(k + j) % N] = bigint[k];
				bigint[(k + j) % N].push_back(i);
			}
		}
		if (flag == false)
			noupdate++;
		if (noupdate == N || bigint[0].size() > 0)
			break;
	}
	if (bigint[0].size() == 0)
		cout << "M is not exist!" << endl;
	else
		show(bigint[0]);
	return 0;
}
