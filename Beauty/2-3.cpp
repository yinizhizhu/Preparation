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

int main(){
	int id[100], i;
	for (i = 0; i < 49; i++)
		id[i] = i;
	for (i = 49; i < 100; i++)
		id[i] = 50;
	cout << find(id, 100) << endl;
	return 0;
}