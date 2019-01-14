#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

vector<int> maxK(int k, vector<int>& con) {
	int i;
	vector<int> ans;
	priority_queue<int, vector<int>, greater<int>> Q;
	for (i = 0; i < k && i < con.size(); i++)
		Q.push(con[i]);
	for (; i < con.size(); i++) {
		if (Q.top() < con[i]) {
			Q.pop();
			Q.push(con[i]);
		}
	}
	for (; Q.size(); Q.pop())
		ans.push_back(Q.top());
	return ans;
}

vector<int> minK(int k, vector<int>& con) {
	int i;
	vector<int> ans;
	priority_queue<int, vector<int>, greater<int>> Q;
	for (i = 0; i < k && i < con.size(); i++)
		Q.push(con[i]);
	for (; i < con.size(); i++) {
		if (Q.top() > con[i]) {
			Q.pop();
			Q.push(con[i]);
		}
	}
	for (; Q.size(); Q.pop())
		ans.push_back(Q.top());
	return ans;
}

void show(vector<int>& ans) {
	cout << "The vector: ";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << endl;
}

int main(){
	vector<int> container;
	for (int i = 0; i < 100; i++)
		container.push_back(i);
	show(maxK(10, container));
	show(minK(10, container));
	return 0;
}
