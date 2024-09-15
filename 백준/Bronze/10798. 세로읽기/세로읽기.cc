#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	char arr[15][15]{};
	
	string s[5];
	for (int i = 0; i < 5; ++i)
		cin >> s[i];

	for (int i = 0; i < 15; ++i)
		for (int j = 0; j < 5; ++j)
			if (s[j].length() > i)
				cout << s[j][i];

	return 0;
}