#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;

		bool isPal = true;
		for (int j = 0; j < s.length() / 2; ++j) {
			if (s[j] != s[s.length() - j - 1])
				isPal = false;
		}

		if (isPal)
			++cnt;
	}

	cout << cnt* (cnt - 1);


	return 0;
}
