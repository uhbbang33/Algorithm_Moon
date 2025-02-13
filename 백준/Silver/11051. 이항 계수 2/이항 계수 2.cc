#include <iostream>
using namespace std;

#define MOD 10007

int dp[1001][1001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; ++i) {
		dp[i][0] = 1;
		dp[i][i] = 1;
	}

	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j < i; ++j) 
			dp[i][j] = (dp[i - 1][j - 1] % MOD + dp[i - 1][j] % MOD) % MOD;

	cout << dp[n][k];

	return 0;
}
