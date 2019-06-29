#include<stdio.h>

int main() {
	int i, j, tmp;
	int t, n, maxn, sum, a, b, A, B;
	scanf("%d", &t);
	for (i = 1; i <= t; i++) {
		scanf("%d", &n);
		sum = maxn = -1001;
		for (j = 1; j <= n; j++) {
			scanf("%d", &tmp);
			if (sum < 0)
				sum = tmp, a = b = j;
			else
				sum += tmp, ++b;
			if (maxn < sum)
				maxn = sum, A = a, B = b;
		}
		printf("Case %d:\n%d %d %d\n", i, maxn, A, B);
		if (i - t)	printf("\n");
	}
	return 0;
}