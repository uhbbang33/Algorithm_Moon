#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string s;
	cin >> s;
	--n;

	while (n--) {
		string curStr;
		cin >> curStr;
		
		for (int i = 0; i < s.length(); ++i) {
			if (curStr[i] != s[i])
				s[i] = '?';
		}
	}

	cout << s;

	return 0;
}