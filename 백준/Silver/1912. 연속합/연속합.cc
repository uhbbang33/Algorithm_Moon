#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1000000]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n = 0;
	cin >> n;
	
	vector<int> v;
	v.push_back(0);

	int num;
	int max = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> num;
		v.push_back(num);
		
		if (i == 1)
			max = dp[i] = num;

		if (v[i] >= dp[i - 1] + v[i])
			dp[i] = v[i];
		else
			dp[i] = dp[i - 1] + v[i];

		if (dp[i] > max)
			max = dp[i];
	}

	cout << max;

	return 0;
}