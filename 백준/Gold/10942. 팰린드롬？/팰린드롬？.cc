#include <iostream>
using namespace std;

bool dp[2001][2001]{};
int num[2001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> num[i];
		
		// 길이 1
		dp[i][i] = true;
	}

	// 길이 2
	for (int i = 1; i < n; ++i)
		if (num[i] == num[i + 1])
			dp[i][i + 1] = true;

	// 길이 3 이상
	for (int i = 3; i <= n; ++i) {
		for (int j = 1; j <= n - i + 1; ++j) {
			int k = i + j - 1;
			if (num[j] == num[k] && dp[j + 1][k - 1])
				dp[j][k] = true;
		}
	}

	cin >> m;

	for (int i = 0; i < m; ++i) {
		int s, e;
		cin >> s >> e;

		cout << dp[s][e] << "\n";
	}

	return 0;
}