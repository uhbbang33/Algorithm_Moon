#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	while (cin >> s) {
		if (s == "end")
			break;

		int vCnt = 0, cCnt = 0;
		bool isAcceptable = false;
		char lastChar = '1';

		for (char c : s) {
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
				isAcceptable = true;
				++vCnt;
				cCnt = 0;
			}
			else {
				vCnt = 0;
				++cCnt;
			}

			if (vCnt == 3 || cCnt == 3) {
				isAcceptable = false;
				break;
			}

			if (lastChar == c) {
				if (c != 'e' && c != 'o') {
					isAcceptable = false;
					break;
				}
			}

			lastChar = c;
		}

		cout << "<" << s << "> is ";
		if (!isAcceptable)
			cout << "not ";
		cout << "acceptable.\n";
	}

	return 0;
}