#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int n, k;
		cin >> n >> k;

		vector<int> d(n + 1);
		vector<int> dp(n + 1);
		vector<int> cnt(n + 1, 0);
		vector<vector<int>> v(n + 1);

		for (int j = 1; j <= n; ++j) {
			cin >> d[j];
			dp[j] = -1;
		}

		for (int j = 0; j < k; ++j) {
			int x, y;
			cin >> x >> y;

			v[x].push_back(y);
			++cnt[y];
		}

		int w;
		cin >> w;

		queue<int> q;
		for (int i = 1; i <= n; ++i)
			if (cnt[i] == 0) {
				q.push(i);
				dp[i] = d[i];
			}

		while (!q.empty()) {
			int building = q.front();
			q.pop();

			for (int nextBuilding : v[building]) {
				dp[nextBuilding] = max(dp[nextBuilding], d[nextBuilding] + dp[building]);

				if (--cnt[nextBuilding] == 0)
					q.push(nextBuilding);
			}
		}

		cout << dp[w] << "\n";
	}

	return 0;
}