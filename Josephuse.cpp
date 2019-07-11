#include <iostream>

using namespace std;

int Josephuse(unsigned int n, unsigned int m) {
	if (n < 1 || m < 1) return -1;
	int ans = 0, i;
	for (i = 2; i <= n; i++) ans = (ans + m) % i;
	return ans;
}

int main() {
	cout << Josephuse(0, 0) << endl;
	cout << Josephuse(10, 4) << endl;
	return 0;
}
