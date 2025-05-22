#include <iostream>
using namespace std;

int dp[1001]{};
int p[1001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> p[i];

	for (int i = 1; i <= n; ++i) {
		dp[i] = p[i];

		for (int j = 1; j <= i; ++j) {
			if (i % j == 0)
				dp[i] = min(dp[i], (i / j) * dp[j]);

			dp[i] = min(dp[i], dp[i - j] + dp[j]);
		}
	}

	cout << dp[n];

	return 0;
}