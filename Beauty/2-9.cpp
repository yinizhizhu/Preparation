#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
	vector<int> container;
	Solution(int n) {
		int N = n;
		container.push_back(0);
		container.push_back(1);
		for (int i = 0; i < N; i++)
			container.push_back(-1);
	}
	~Solution() {}
	int Fibonacci(int n) {
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
	int Fibonacci2(int n) {
		if (container[n] != -1)
			return container[n];
		container[n] = Fibonacci2(n - 1) + Fibonacci2(n - 2);
		return container[n];
	}
};

int main() {
	Solution tmp(1000);
	cout << tmp.Fibonacci2(100) << endl;;
	cout << tmp.Fibonacci(100) << endl;
	return 0;
}