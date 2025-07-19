#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string l, r;
	cin >> l >> r;

	int result = 0;
	if (l.length() == r.length()) {
		for (int i = 0; i < l.length(); ++i) {
			if (l[i] == r[i]) {
				if (l[i] == '8')
					++result;
			}
			else
				break;
		}
	}
	cout << result;

	return 0;
}