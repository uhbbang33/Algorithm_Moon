#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int result = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (!isalpha(s[i]))
			result += pow(16, s.length() - i - 1) * (s[i] - '0');
		else
			result += pow(16, s.length() - i - 1) * (s[i] - 'A' + 10);
	}

	cout << result;

	return 0;
}
