#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; ++i) {
		stack<string> st;
		string s;

		getline(cin, s);

		string temp;
		for (int j = 0; j < s.length(); ++j) {
			if (s[j] == ' ') {
				st.push(temp);
				temp.clear();
			}
			else
				temp += s[j];
		}
		if (!temp.empty())
			st.push(temp);


		cout << "Case #" << i + 1 << ": ";
		while (!st.empty()) {
			cout << st.top() << " ";
			st.pop();
		}
		cout << "\n";
	}
	

	return 0;
}