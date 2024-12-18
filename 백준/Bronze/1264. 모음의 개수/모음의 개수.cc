#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s = "";
	while (getline(cin, s)) {
		if (s == "#")
			break;

		int cnt = 0;
		for (char c : s)
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
				|| c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
				++cnt;
		cout << cnt << "\n";
	}

	return 0;
}