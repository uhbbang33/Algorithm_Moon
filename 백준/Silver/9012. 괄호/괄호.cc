#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	string s = "";
	int countL = 0, countR = 0;
	bool isNO = false;
	for (int i = 0; i < n; ++i) {
		countL = 0;
		countR = 0;
		isNO = false;

		cin >> s;

		for (int j = 0; j < s.size(); ++j) {
			if (s[j] == '(') ++countL;
			else ++countR;

			if (countL < countR)
				isNO = true;
		}

		if (countL == countR && !isNO)
			cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}