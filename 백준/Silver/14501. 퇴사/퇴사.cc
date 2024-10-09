#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int dp[16]{}, t[16]{}, p[16]{};
	int maxCoin = 0;

	for (int i = 0; i < n; ++i)
		cin >> t[i] >> p[i];

	for (int i = 0; i < n; ++i) {
		if (t[i] + i > n)
			continue;

		dp[i] += p[i];
		dp[i + t[i]] = max(dp[i], dp[i + t[i]]);
		
		for (int j = i + t[i]; j < n; ++j) 
			dp[j] = max(dp[j], dp[i]);

		maxCoin = max(maxCoin, dp[i]);
	}

	cout << maxCoin;

	return 0;
}