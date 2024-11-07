#include <iostream>
using namespace std;

#define MOD 1000000000
long long dp[101][10]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= 9; ++i)
		dp[1][i] = 1;

	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j <= 9; ++j) {
			if (j == 0)
				dp[i][j] = dp[i - 1][1];
			else if (j == 9)
				dp[i][j] = dp[i - 1][8];
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];

			dp[i][j] %= MOD;
		}
	}

	long long result = 0;
	for (int i = 0; i <= 9; ++i)
		result += dp[n][i];

	result %= MOD;

	cout << result;

	return 0;
}