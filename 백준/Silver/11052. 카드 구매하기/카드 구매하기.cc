#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int* p = new int[n + 1] {};
	int* dp = new int[n + 1] {};
	
	for (int i = 1; i <= n; ++i)
		cin >> p[i];

	dp[1] = p[1];

	for (int i = 1; i <= n; ++i) {
		int curMax = p[i];
		for (int j = i - 1; j > 0; --j) 
			curMax = max(curMax, dp[j] + dp[i - j]);
		
		dp[i] = curMax;
	}

	cout << dp[n];

	delete[] p, dp;

	return 0;
}