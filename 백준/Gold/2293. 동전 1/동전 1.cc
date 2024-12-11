#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[10001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> coin(n);
	for (int i = 0; i < n; ++i)
		cin >> coin[i];

	dp[0] = 1;

	for (int c : coin) 
		for (int j = c; j <= k; ++j) 
			dp[j] += dp[j - c];

	cout << dp[k];

	return 0;
}