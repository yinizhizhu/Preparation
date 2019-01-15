#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int gcd1(int a, int b) {
	if (b) return gcd1(b, a%b);
	return a;
}

int gcd2(int a, int b) {
	if (a < b)
		return gcd2(b, a);
	if (b == 0)
		return a;
	return gcd2(a - b, b);
}

int gcd3(int a, int b) {
	if (a < b)
		return gcd3(b, a);
	if (b == 0)
		return a;
	int x = a & 0x01, y = b & 0x01;
	if (x == 0) {
		if (y == 0)
			return (gcd3(a >> 1, b >> 1) << 1);
		return gcd3(a >> 1, b);
	}
	if (y == 0)
		return gcd3(a, b >> 1);
	return gcd3(b, a - b);
}

int main(){
	cout << gcd1(10, 90) << endl;
	cout << gcd2(10, 90) << endl;
	cout << gcd3(10, 90) << endl;
	return 0;
}
