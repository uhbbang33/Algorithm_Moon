#include <iostream>
#include <numeric>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	int dp[10]{};
	for (int i = 0; i < 10; ++i)
		dp[i] = 1;

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < 9; ++j) {
			dp[j + 1] += dp[j] % 10007;
			dp[j + 1] %= 10007;
		}
	}

	cout << accumulate(dp, dp+10, 0) % 10007;
	
	return 0;
}