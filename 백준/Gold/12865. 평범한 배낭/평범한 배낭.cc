#include <iostream>
using namespace std;

int dp[101][100001]{};	// 물건, 무게, 값은 가치
int w[101]{}, v[101]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
		cin >> w[i] >> v[i];

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			if (j >= w[i])
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	
	cout << dp[n][k];

	return 0;
}