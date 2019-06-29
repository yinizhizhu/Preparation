#include <stdio.h>
int s[100001];
int a[100001];
void fun(int s[], int n, int num) {
	int i = 0, j = n - 1, mid;
	for (; i <= j;) {
		mid = (i + j) >> 1;
		if (s[mid] > num)  j = mid - 1;
		else if (s[mid] == num) return;
		else i = mid + 1;
	}
	s[i] = num;
}
int main() {
	int i, x, n, len, t = 0;
	while (~scanf("%d", &n)) {
		for (i = 0; i < n; i++) {
			scanf("%d", &x);
			a[i] = x;
		}
		s[0] = a[0];
		len = 1;
		for (i = 1; i < n; i++) {
			if (a[i] > s[len - 1])  s[len++] = a[i];
			else  fun(s, len, a[i]);
		}
		printf("%d\n", len);
	}
	return 0;
}