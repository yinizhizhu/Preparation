#include <iostream>
#include <stdlib.h>

using namespace std;

int sum1(int n) {
	int ans = 0, factor = 1;
	int lowNum = 0, curNum = 0, highNum = 0;
	for (; n / factor != 0;) {
		lowNum = n - (n / factor)*factor;
		curNum = n / factor % 10;
		highNum = n / (factor * 10);
		switch (curNum)
		{
		case 0:
			ans += highNum*factor;
			break;
		case 1:
			ans += highNum *factor + lowNum;
			break;
		default:
			ans += (highNum + 1)*factor;
			break;
		}
		factor *= 10;
	}
	return ans;
}

int main(){
	cout << sum1(2) << endl;
	cout << sum1(12) << endl;
	return 0;
}