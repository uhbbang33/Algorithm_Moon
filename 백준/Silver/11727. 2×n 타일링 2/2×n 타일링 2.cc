#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	int dp[1001]{};
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n; ++i) {
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
	}

	cout << dp[n];

	return 0;
}