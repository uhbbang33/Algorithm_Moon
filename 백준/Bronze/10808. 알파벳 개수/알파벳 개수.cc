#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	int result[26]{};

	for (int i = 0; i < s.length(); ++i)
		++result[s[i] - 'a'];

	for (int i = 0; i < 26; ++i)
		cout << result[i] << " ";

	return 0;
}