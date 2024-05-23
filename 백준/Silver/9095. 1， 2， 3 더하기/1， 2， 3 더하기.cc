#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 0;
	cin >> t;

	int dp[11]{0, 1, 2, 4};
	for (int i = 4; i <= 10; ++i) {
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	}

	int n = 0;
	for (int i = 0; i < t; ++i) {
		cin >> n;
		cout << dp[n] << "\n";
	}

	return 0;
}