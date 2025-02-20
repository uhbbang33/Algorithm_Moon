#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[501]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>> v(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end());

	int maxDp = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i - 1; j >= 0; --j)
			if (v[j].second < v[i].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		maxDp = max(dp[i], maxDp);
	}

	cout << n - maxDp;
	return 0;
}
