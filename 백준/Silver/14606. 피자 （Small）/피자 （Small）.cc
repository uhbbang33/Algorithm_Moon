#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int dp[11]{};
	dp[2] = 1;

	for (int i = 3; i <= n; ++i) 
		dp[i] = dp[i - 1] + i - 1;

	cout << dp[n];

	return 0;
}