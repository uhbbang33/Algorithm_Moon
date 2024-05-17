#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s = "";
	getline(cin, s);

	while (s != ".") {
		stack<char> st;
		for (char c : s) {
			if (c == '(' || c == '[')
				st.push(c);
			else if (c == ')') {
				if (!st.empty()&& st.top() == '(')
					st.pop();
				else
					st.push(')');
			}
			else if (c == ']') {
				if (!st.empty() && st.top() == '[')
					st.pop();
				else
					st.push(']');
			}
		}

		if (st.empty())
			cout << "yes\n";
		else cout << "no\n";

		getline(cin, s);
	}


	return 0;
}