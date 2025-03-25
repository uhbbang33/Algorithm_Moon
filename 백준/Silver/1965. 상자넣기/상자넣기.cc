#include <iostream>
using namespace std;

pair<int, int> dp[1001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	dp[0] = { 0,0 };

	int maxBox = 0;

	for (int i = 1; i <= n; ++i) {
		int box;
		cin >> box;

		for (int j = i - 1; j >= 0; --j) {
			if (dp[j].second < box && dp[i].first < dp[j].first + 1) {
				dp[i].first =dp[j].first + 1;
				maxBox = max(maxBox, dp[i].first);
			}
		}

		dp[i].second = box;
	}

	cout << maxBox;

	return 0;
}