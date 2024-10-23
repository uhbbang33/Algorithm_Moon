#include <iostream>
using namespace std;

pair<long long, long long> dp[90]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	dp[1] = { 0, 1 };
	dp[2] = { 1, 0 };
	dp[3] = { 1, 1 };
	for (int i = 4; i <= n; ++i) {
		dp[i].first = dp[i - 1].first + dp[i - 1].second;
		dp[i].second = dp[i - 1].first;
	}

	cout << dp[n].first + dp[n].second;

	return 0;
}