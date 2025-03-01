#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;

		if (s.length() > 10)
			continue;

		int cute = 0, notCute = 0;
		int num = 0;
		for (int j = 0; j < s.length(); ++j) {
			if (s[j] >= 'A' && s[j] <= 'Z')
				++notCute;
			else if (s[j] >= 'a' && s[j] <= 'z')
				++cute;
			else if (s[j] >= '0' && s[j] <= '9')
				++num;
		}
		if (num == s.length() || cute < notCute)
			continue;

		cout << s;
	}

	return 0;
}
