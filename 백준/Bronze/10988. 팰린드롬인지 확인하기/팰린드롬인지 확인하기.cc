#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int result = 1;
	for (int i = 0; i < s.length() /2 + 1; ++i) {
		if (s[i] != s[s.length() - i - 1]) {
			result = 0;
			break;
		}
	}
	cout << result;

	return 0;
}