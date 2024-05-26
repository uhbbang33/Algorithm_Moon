#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n = 0;
	cin >> n;
	
	vector<int> nums;
	nums.push_back(0);
	vector<int> dp;
	dp.push_back(0);

	int num;
	int max = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> num;
		nums.push_back(num);
		dp.push_back(0);

		if (i == 1)
			max = dp[i] = num;

		if (nums[i] >= dp[i - 1] + nums[i])
			dp[i] = nums[i];
		else
			dp[i] = dp[i - 1] + nums[i];

		if (dp[i] > max)
			max = dp[i];
	}

	cout << max;

	return 0;
}