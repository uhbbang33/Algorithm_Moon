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
	int x = 1;
	
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '(') {
			st.push(s[i]);
			x *= 2;
		}
		else if (s[i] == '[') {
			st.push(s[i]);
			x *= 3;
		}
		else if (s[i] == ')') {
			if (st.empty() || st.top() != '(') {
				std::cout << "0";
				return 0;
			}
			st.pop();
			if (s[i - 1] == '(')
				result += x;
			x /= 2;
		}
		else if (s[i] == ']') {
			if (st.empty() || st.top() != '[') {
				std::cout << "0";
				return 0;
			}
			st.pop();
			if (s[i - 1] == '[')
				result += x;
			x /= 3;
		}
	}

	if (st.empty())
		std::cout << result;
	else
		std::cout << "0";

	return 0;
}