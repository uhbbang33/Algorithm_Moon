#include <iostream>
using namespace std;

int dp[1001][1001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j) {
			int candy;
			cin >> candy;

			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			dp[i][j] += candy;
		}

	cout << dp[n][m];

	return 0;
}