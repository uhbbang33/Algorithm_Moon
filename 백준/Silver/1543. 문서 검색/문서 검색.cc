#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s, word;
	getline(cin, s);
	getline(cin, word);

	int result = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (word[0] == s[i]) {
			bool isSame = true;
			for (int j = 1; j < word.length(); ++j) {
				if (i + j > s.length()) {
					isSame = false;
					break;
				}

				if (word[j] != s[i + j])
					isSame = false;
			}

			if (isSame) {
				++result;
				i += word.length() - 1;
			}
		}
	}

	cout << result;

	return 0;
}