#include <iostream>
using namespace std;

int dp[5001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	if (s[0] == '0') {
		cout << "0";
		return 0;
	}

	dp[0] = 1;
	dp[1] = 1;

	if (s.length() > 1)
		if (s[1] != '0' && (s[0] == '1' || (s[0] == '2' && s[1] <= '6')))
			++dp[1];

	for (int i = 1; i < s.length(); ++i) {
		if (s[i] == '0' && (s[i - 1] != '1' && s[i - 1] != '2')) {
			cout << "0";
			return 0;
		}

		if (s[i] == '0' && i >= 2)
			dp[i] = dp[i - 2];
		else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
			if (i >= 2)
				dp[i] = dp[i - 1] + dp[i - 2];
		}
		else
			dp[i] = dp[i - 1];

		dp[i] %= 1000000;
	}

	cout << dp[s.length() - 1];

	return 0;
}