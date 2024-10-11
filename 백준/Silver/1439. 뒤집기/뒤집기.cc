#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;

	char cur= ' ';
	int zeroCnt = 0, oneCnt = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (cur != s[i]) {
			if (s[i] == '1')
				++oneCnt;
			else if (s[i] == '0')
				++zeroCnt;
		}
		cur = s[i];
	}

	if (zeroCnt == 0 || oneCnt == 0)
		cout << "0";
	else
		cout << min(oneCnt, zeroCnt);

	return 0;
}