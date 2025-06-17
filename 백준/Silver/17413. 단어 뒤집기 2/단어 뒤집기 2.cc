#include <iostream>
#include <string>
#include <stack>
using namespace std;

void PrintStack(stack<char> &st) {
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	getline(cin, s);

	stack<char> st;
	bool isTag = false;

	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '<') {
			isTag = true;
			PrintStack(st);
			cout << s[i];
		}
		else if (s[i] == '>') {
			isTag = false;
			cout << s[i];
		}
		else if (s[i] == ' ') {
			PrintStack(st);
			cout << s[i];
		}
		else if (!isTag)
			st.push(s[i]);
		else
			cout << s[i];
	}
	PrintStack(st);

	return 0;
}