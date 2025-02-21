#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	if (n % 2 != 0) {
		cout << "0";
		return 0;
	}

	int dp[31]{};
	dp[2] = 3;

	for (int i = 4; i <= n; i += 2) {
		dp[i] = dp[i - 2] * dp[2];
		for (int j = i - 4; j > 0; j -= 2) 
			dp[i] += dp[j] * 2;
		dp[i] += 2;
	}

	cout << dp[n];

	return 0;
}
