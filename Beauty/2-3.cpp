#include <iostream>
#include <stdlib.h>

using namespace std;

int find(int* id, int n) {
	int candiate, ntimes, i;
	for (i = ntimes = 0; i < n; i++) {
		if (ntimes == 0)
			candiate = id[i], ntimes = 1;
		else {
			if (candiate == id[i])
				ntimes++;
			else
				ntimes--;
		}
	}
	return candiate;
}

void find3(int* candidate, int* id, int n) {
	int ntimes[3], i, j, k;
	for (j = 0; j < 3; j++) ntimes[j] = 0;
	for (i = 0; i < n; i++) {
		k = -1;
		for (j = 0; j < 3; j++) {
			if (ntimes[j] == 0) {
				candidate[j] = id[i], ntimes[j] = 1;
				k = j;
				break;
			}
			else {
				if (candidate[j] == id[i]) {
					ntimes[j]++;
					k = j;
					break;
				}
			}
		}
		if (k == -1) {
			for (j = 0; j < 3; j++)
				if (ntimes[j] > 0)
					ntimes[j]--;
		}
		//cout << i + 1 << "-" << id[i] << ": ";
		//for (j = 0; j < 3; j++)
		//	cout << "(" << candidate[j] << ", " << ntimes[j] << ") ";
		//cout << endl;
	}
	//cout << "Final: ";
	//for (i = 0; i < 3; i++)
	//	cout << candidate[i] << " ";
	//cout << endl;
}

int main(){
	int id[100], i, candidate[3];

	for (i = 0; i < 49; i++)
		id[i] = i;
	for (i = 49; i < 100; i++)
		id[i] = 50;
	cout << find(id, 100) << endl;

	for (i = 0; i < 26; i++)
		id[i] = 1;
	for (; i < 52; i++)
		id[i] = 2;
	for (; i < 78; i++)
		id[i] = 3;
	for (; i < 100; i++)
		id[i] = i;
	find3(candidate, id, 100);
	for (i = 0; i < 3; i++)
		cout << candidate[i] << " ";
	cout << endl;
	return 0;
}