#include <iostream>
using namespace std;

long long dp[90]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= n; ++i)
		dp[i] = dp[i - 1] + dp[i - 2];
	
	cout << dp[n];

	return 0;
}