#include <iostream>
#include <stack>
using namespace std;

// https://www.acmicpc.net/problem/9012

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	stack<char> s;
	string str;
	bool isVPS = true;

	for (int i = 0; i < n; ++i) {
		isVPS = true;
		cin >> str;

		for (char c : str) {
			if (c == '(')
				s.push(c);
			else if (c == ')' && !s.empty())
				s.pop();
			else {
				isVPS = false;
				break;
			}
		}

		if (!s.empty()) {
			isVPS = false;
			while (!s.empty()) s.pop();
		}

		if (isVPS) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}