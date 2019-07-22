#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

priority_queue<int, vector<int>, greater<int> > Q1; // 最小堆
priority_queue<int> Q2; //最大堆

int main() {
	int i = 0, tmp;
	for (; i < 10; i++) {
		tmp = rand() % 100;
		Q1.push(tmp);
		Q2.push(tmp);
	}

	for (i = 0; i < 10; i++) {
		cout << Q1.top() << "-" << Q2.top() << endl;
		Q1.pop(), Q2.pop();
	}
	return 0;
}