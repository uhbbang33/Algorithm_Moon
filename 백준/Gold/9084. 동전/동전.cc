#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> coins(n);
		for (int i = 0; i < n; ++i)
			cin >> coins[i];

		int m;
		cin >> m;
		vector<int> dp(m + 1);
		dp[0] = 1;

		for (int j = 0; j < n; ++j) 
			for (int i = coins[j]; i <= m; ++i) 
				dp[i] += dp[i - coins[j]];

		cout << dp[m] << "\n";
	}

	return 0;
}