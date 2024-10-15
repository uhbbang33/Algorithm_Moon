#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	map<char, int> m;

	for (int i = 0; i < s.length(); ++i)
		++m[s[i]];

	int odd = 0;
	char oddChar;
	string pal = "";

	for (auto a : m) {
		if (a.second % 2 != 0) {
			++odd;
			oddChar = a.first;
		}
		for (int i = 0; i < a.second / 2; ++i)
			pal += a.first;
	}

	if (odd > 1)
		cout << "I'm Sorry Hansoo";
	else {
		cout << pal;

		if (odd == 1)
			cout << oddChar;

		for (int i = pal.length() - 1; i >= 0; --i)
			cout << pal[i];
	}

	return 0;
}