#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	int dp[301]{};
	int num;
	vector<int> v;
	
	for (int i = 1; i <= n; ++i) {
		cin >> num;
		v.push_back(num);
		dp[i] = dp[i - 1] + num;

		if (i >= 3)
			dp[i] = max(dp[i - 3] + v[i - 2] + num, dp[i - 2] + num);
	}
	cout << dp[n];

	return 0;
}