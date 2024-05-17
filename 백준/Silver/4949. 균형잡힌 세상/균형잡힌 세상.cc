#include <iostream>
#include <string>
#include <stack>
using namespace std;

//12:16

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin.ignore();
	string s = "";
	getline(cin, s);

	while (s != ".") {
		stack<char> st;
		for (char c : s) {
			if (c == '.')
				break;

			if (c == '(') 
				st.push('(');
			else if (c == ')') {
				if (!st.empty()&& st.top() == '(')
					st.pop();
				else
					st.push(')');
			}
			else if (c == '[')
				st.push('[');
			else if (c == ']') {
				if (!st.empty() && st.top() == '[')
					st.pop();
				else
					st.push(']');
			}
		}

		if (st.empty())
			cout << "yes" << endl;
		else cout << "no" << endl;

		getline(cin, s);
	}


	return 0;
}