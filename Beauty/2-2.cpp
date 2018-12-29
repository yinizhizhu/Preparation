#include <iostream>
#include <stdlib.h>

using namespace std;

int factorial1(int n) {
	int ans = 0, i, j;
	for (i = 5; i <= n; i++) {
		j = i;
		for (; j % 5 == 0; j /= 5)
			ans++;
	}
	return ans;
}

int factorial2(int n) {
	int ans = 0;
	for (n /= 5; n; n /= 5) {
		cout << n << endl;
		ans += n;
	}
	return ans;
}

int factorial3(int n) {
	int ans = 0;
	for (n >>= 1; n; n >>= 1)
		ans += n;
	return ans;
}

int count(int n) {
	int ans = 0;
	for (; n; n&=(n-1))
		ans++;
	return ans;
}

int factorial4(int n) {
	return n - count(n);
}

int main(){
	cout << factorial1(100) << endl;
	cout << factorial2(100) << endl;
	cout << factorial3(100) << endl;
	cout << factorial4(100) << endl;
	return 0;
}