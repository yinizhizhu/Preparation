#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

void show(vector<int>& t) {
	for (int i = 0; i < t.size(); i++)
		cout << t[i] << ",";
	cout << endl;
}

void search(vector<int>& t, int sum) {
	int i = 0, j = t.size() - 1, tmp;
	for (; i < j;) {
		tmp = t[i] + t[j];
		if (tmp == sum) {
			cout << t[i] << ", " << t[j] << endl;
			return;
		}
		else if (tmp > sum) j--;
		else i++;
	}
}

int main() {
	int i;
	vector<int> tmp;
	for (i = 0; i < 30; i++) tmp.push_back(rand() % 30 + 1);
	show(tmp);
	sort(tmp.begin(), tmp.end());
	show(tmp);
	search(tmp, 30);
	return 0;
}
