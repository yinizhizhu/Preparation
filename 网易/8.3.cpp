//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <stack>
//#include <functional>
//#include <unordered_set>
//#include <queue>
//
//using namespace std;
//priority_queue<int, vector<int>, greater<int>> Q;
//priority_queue<int> Q2;
//
////struct TreeNode {
////	int val;
////	TreeNode *left;
////	TreeNode *right;
////	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
////};
////
////// Definition for a Node.
////class Node {
////public:
////	int val;
////	vector<Node*> children;
////
////	Node() {}
////
////	Node(int _val, vector<Node*> _children) {
////		val = _val;
////		children = _children;
////	}
////};
////
////class Solution {
////public:
////	int largest1BorderedSquare(vector<vector<int>>& grid) {
////		return 0;
////	}
////};
//
//void permutation2(char* pStr, char* pBegin) {
//	if (*pBegin == '\0') printf("%s\n", pStr);
//	else {
//		char tmp;
//		for (char* step = pBegin; *step != '\0'; step++) {
//			tmp = *step;
//			*step = *pBegin;
//			*pBegin = tmp;
//
//			permutation2(pStr, pBegin + 1);
//
//			tmp = *step;
//			*step = *pBegin;
//			*pBegin = tmp;
//		}
//	}
//}
//
//int main() {
//
//	return 0;
//}

#include <iostream>
#include <string>

using namespace std;

string rever(string& str) {
	string ans = "";
	bool tag = false;
	for (auto p : str) {
		if (tag) {
			if (p == '1') ans += '0';
			else ans += '1';
		}
		else {
			if (p == '0') {
				ans += '1';
				tag = true;
			}
		}
	}
	return ans;
}

bool check(int x, int y, int z) {
	for (int i = z / x; i >= 0; i--) {
		int tmp = z - i * x;
		if (tmp % y == 0) return true;
	}
	return false;
}

bool match(string& str, string& t, int h) {
	int i;
	for (i = 0; i < str.size() && h < t.size(); i++, h++)
		if (str[i] != t[h]) return false;
	if (i == str.size()) return true;
	return false;
}

bool check2(string& s, string& r, string& t, int h) {
	if (h >= t.size()) return true;
	bool h1 = false, h2 = false;
	if (match(s, t, h)) h1 = check2(s, r, t, h + s.size());
	if (match(r, t, h)) h2 = check2(s, r, t, h + r.size());
	return (h1 || h2);
}

int main() {
	string s, t, r;
	int n;
	for (cin >> n; n; n--) {
		cin >> s >> t;
		r = rever(s);
		if (check(s.size(), r.size(), t.size())) {
			if (check2(s, r, t, 0)) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		else cout << "NO" << endl;
	}
	return 0;
}
/*
2
5
17 6 17 11 17
1
3
1 2 4
*/