#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		string s;
		cin >> s;

		int l = 1;
		int isPalindrome = 1;
		for (int j = 0; j < s.length() / 2; ++j) {
			if (s[j] != s[s.length() - j - 1]) {
				isPalindrome = 0;
				break;
			}
			++l;
		}

		cout << isPalindrome << " " << l << "\n";
	}

	return 0;
}