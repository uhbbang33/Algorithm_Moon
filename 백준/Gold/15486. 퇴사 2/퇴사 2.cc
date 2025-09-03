#include <iostream>
using namespace std;

int dp[1500001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int result = 0;

	for (int i = 0; i < n; ++i) {
		int t, p;
		cin >> t >> p;

		dp[i + 1] = max(dp[i], dp[i + 1]);

		if (i + t> n)
			continue;

		dp[i + t] = max(dp[i + t], dp[i] + p);

		result = max(result, dp[i + t]);
	}

	cout << result;

	return 0;
}