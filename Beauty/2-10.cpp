#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>

using namespace std;

void findMaxMin(vector<int>& con) {
	int top, down, i = 3;
	if (con.size() == 1)
		top = down = con[0];
	else {
		if (con[0] > con[1])
			top = con[0], down = con[1];
		else
			top = con[1], down = con[0];
	}
	for (; i < con.size(); i += 2) {
		if (con[i - 1] > con[i]) {
			top = max(con[i - 1], top);
			down = min(con[i], down);
		}
		else {
			top = max(con[i], top);
			down = min(con[i - 1], down);
		}
	}
	cout << "Max: " << top << ", Min: " << down << endl;
	sort(con.begin(), con.end());
	cout << "Max: " << con[con.size()-1] << ", Min: " << con[0] << endl;
}

int main() {
	int i;
	vector<int> con;
	for (i = 0; i < 99; i++)
		con.push_back(rand() % 999 + 1);
	findMaxMin(con);
	return 0;
}