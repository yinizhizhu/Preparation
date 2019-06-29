#include <stdio.h>

int s[500001];
int a[500001];

void fun(int s[], int n, int num) {
	int i = 0, j = n - 1, mid;
	for (; i <= j;) {
		mid = (i + j) >> 1;
		if (s[mid] > num)  j = mid - 1;
		else i = mid + 1;
	}
	s[i] = num;
}

int main() {
	int i, p, r, n, len, t = 0;
	while (~scanf("%d", &n)) {
		for (i = 0; i < n; i++) {
			scanf("%d%d", &p, &r);
			a[p - 1] = r;
		}
		s[0] = a[0];
		len = 1;
		for (i = 1; i < n; i++) {
			if (a[i] > s[len - 1])  s[len++] = a[i];
			else  fun(s, len, a[i]);
		}
		printf("Case %d:\n", ++t);
		if (len == 1) printf("My king, at most %d road can be built.\n\n", len);
		else  printf("My king, at most %d roads can be built.\n\n", len);
	}
	return 0;
}