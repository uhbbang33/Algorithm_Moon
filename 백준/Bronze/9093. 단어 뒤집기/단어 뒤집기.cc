#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	cin.ignore();

	while (t--) {
		string s;
		getline(cin, s);
		s += ' ';

		stack<char> st;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == ' ') {
				while (!st.empty()) {
					cout << st.top();
					st.pop();
				}
				cout << " ";
			}
			else
				st.push(s[i]);
		}

		cout << "\n";
	}

	return 0;
}