#include <iostream>
using namespace std;

int dp[1000001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		dp[i] = i;

	for (int i = 2; i <= n; ++i) {
		dp[i] = min(dp[i], dp[i - 1] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
	}

	cout << dp[n] - 1 << "\n";

	while (n != 0) {
		cout << n << " ";
		if (dp[n] == dp[n - 1] + 1)
			--n;
		else if (n % 2 == 0 && dp[n] == dp[n / 2] + 1)
			n /= 2;
		else if (n % 3 == 0 && dp[n] == dp[n / 3] + 1)
			n /= 3;
	}

	return 0;
}