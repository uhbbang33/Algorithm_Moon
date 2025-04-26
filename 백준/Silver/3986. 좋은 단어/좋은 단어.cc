#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int result = 0;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;

		if (s.length() % 2 != 0)
			continue;

		stack<int> st;

		for (int j = 0; j < s.length(); ++j) {
			if (!st.empty() && st.top() == s[j])
				st.pop();
			else
				st.push(s[j]);
		}
		
		if (st.empty())
			++result;
	}

	cout << result;

	return 0;
}