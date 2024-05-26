#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int dp[1000]{};
	int n = 0;
	cin >> n;
	
	vector<int> v;
	v.push_back(0);
	
	int num = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> num;
		v.push_back(num);
		dp[i] = 1;
	}

	int result = 1;
	for (int i = 2; i <= n; ++i) {
		if (v[i] == v[i - 1])
			dp[i] = dp[i - 1];
		else {
			int max = 0;
			for (int j = i - 1; j >= 1; --j) {
				if (v[j] < v[i] && max < dp[j])
				{
					dp[i] = dp[j] + 1;
					max = dp[j];
				}
			}
		}
		if (dp[i] > result)
			result = dp[i];
	}
	
	cout << result;

	return 0;
}