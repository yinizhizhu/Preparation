#include <iostream>

using namespace std;

const int N = 15;

int con[N], k = 3, b = N - 3;

void show() {
	for (int i = 0; i < N; i++)
		cout << con[i] << "\t";
	cout << endl;
}

int partition(int h, int t) {
	if (h < t) {
		int temp = con[h];
		while (h < t) {
			while (h < t && con[t] >= temp) t--;
			if (h < t) con[h++] = con[t];
			while (h < t && con[h] <= temp) h++;
			if (h < t) con[t--] = con[h];
		}
		con[h] = temp;
		return h;
	}
	return h;
}

void quickSort(int h, int t) {
	if (h < t) {
		int m = partition(h, t);
		if (m == b) {
			cout << con[m] << endl;
			return;
		}
		else if (m > b)
			quickSort(h, m - 1);
		else
			quickSort(m + 1, t);
	}
}

int main() {
	for (int i = 0; i < N; i++) con[i] = rand() % 1000;
	show();
	quickSort(0, N - 1);
	show();
}