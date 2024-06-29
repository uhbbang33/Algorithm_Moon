#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;

	string maxStr = "";
	string minStr = "";
	
	int mCount = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'M')
			++mCount;
		else if (s[i] == 'K') {
			maxStr += "5";

			if (mCount >= 1) {
				minStr += "1";
				for (int i = 0; i < mCount; ++i) {
					maxStr += "0";
					if (i != mCount - 1)
						minStr += "0";
				}
				mCount = 0;
			}
			minStr += "5";
		}
	}
	if (mCount >= 1) {
		minStr += "1";
		for (int i = 0; i < mCount; ++i) {
			if (i != mCount - 1)
				minStr += "0";
			maxStr += "1";
		}
	}

	cout << maxStr << "\n";
	cout << minStr;

	return 0;
}