#include <iostream>
using namespace std;

int dp[100001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, w, v;
	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		cin >> w >> v;

		for (int j = k; j >= w; --j)
			dp[j] = max(dp[j - w] + v, dp[j]);
	}

	cout << dp[k];

	return 0;
}