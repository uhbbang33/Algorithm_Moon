#include <iostream>
#include <vector>
using namespace std;

#define MAX_RESULT 10001

int dp[10001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> coins(n + 1);

	for (int i = 1; i <= n; ++i)
		cin >> coins[i];
	
	for (int i = 1; i <= k; ++i)
		dp[i] = MAX_RESULT;

	for (int i = 1; i <= n; ++i)
		for (int j = coins[i]; j <= k; ++j)
			dp[j] = min(dp[j], dp[j - coins[i]] + 1);

	if (dp[k] == MAX_RESULT)
		cout << "-1";
	else
		cout << dp[k];
	
	return 0;
}
