#include <iostream>
#include <vector>
using namespace std;

int dp[1001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> v(n + 1);
	dp[0] = 1;

	int result = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
		dp[i] = 1;

		for (int j = i - 1; j > 0; --j) 
			if (v[i] < v[j]) 
				dp[i] = max(dp[j] + 1, dp[i]);

		result = max(result, dp[i]);
	}

	cout << result;

	return 0;
}
