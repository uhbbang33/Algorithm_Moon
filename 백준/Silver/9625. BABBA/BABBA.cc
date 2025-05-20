#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int k;
	cin >> k;

	pair<int,int> dp[46]{};
	dp[1].second = 1;

	for (int i = 2; i <= k; ++i) {
		dp[i].first = dp[i - 1].second;
		dp[i].second = dp[i - 1].first + dp[i - 1].second;
	}

	cout << dp[k].first << " " << dp[k].second;

	return 0;
}