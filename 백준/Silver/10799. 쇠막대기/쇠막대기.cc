#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;

	stack<char> st;
	int result = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '(') {
			st.push('(');
		}
		else if (s[i] == ')') {
			if (s[i - 1] != '(') {
				st.pop();
				result += 1;
			}
			else if (st.top() == '(') {
				st.pop();
				result += st.size();
			}
		}
	}
	cout << result;

	return 0;
}