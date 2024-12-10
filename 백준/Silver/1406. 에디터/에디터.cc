#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	stack<char> left, right;
	for (int i = 0; i < s.length(); ++i)
		left.push(s[i]);

	int m;
	cin >> m;

	for (int i = 0; i < m; ++i) {
		char c;
		cin >> c;

		switch(c) {
		case 'L':
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
			break;
		case 'D':
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
			break;
		case 'B':
			if (!left.empty())
				left.pop();
			break;
		case 'P':
			char tempChar;
			cin >> tempChar;
			left.push(tempChar);
			break;
		default:
			break;
		}
	}

	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}
	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}

	return 0;
}