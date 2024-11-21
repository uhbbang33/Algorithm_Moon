#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	int result = 0;
	for (int i = 1; i <= n; ++i) {
		string s = to_string(i);

		for (int j = 0; j < s.length(); ++j) {
			string temp = "";
			temp += s[j];
			temp += s[j + 1];
			if (temp == "50" && i != n) {
				++result;
				break;
			}
		}
		++result;
	}
	cout << result;

	return 0;
}