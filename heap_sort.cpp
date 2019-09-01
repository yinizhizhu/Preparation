#include <iostream>

using namespace std;

void swap(int con[], int a, int b) {
	int tmp = con[a];
	con[a] = con[b];
	con[b] = tmp;
}

void heapify(int con[], int n, int i) {
	if (i >= n) return;
	int l = (i << 1) + 1;
	int r = l + 1, maxn = i;
	if (l < n && con[l] > con[maxn]) maxn = l;
	if (r <n && con[r] > con[maxn]) maxn = r;
	if (maxn != i) {
		swap(con, maxn, i);
		heapify(con, n, maxn);
	}
}

void build_heap(int con[], int n) {
	int i = (n - 1) >> 1;
	for (; i >= 0; i--) heapify(con, n, i);
}

void heap_sort(int con[], int n) {
	build_heap(con, n);
	for (--n; n >= 0; n--) {
		swap(con, n, 0);
		heapify(con, n, 0);
	}
}

void show(int con[], int n) {
	for (int i = 0; i < n; i++)
		cout << con[i] << " ";
	cout << endl;
}

int main() {
	int n = 6;
	int con[6] = { 4, 10, 3, 5, 1, 2 };
	show(con, n);
	//build_heap(con, n);
	heap_sort(con, n);
	show(con, n);
	return 0;
}
