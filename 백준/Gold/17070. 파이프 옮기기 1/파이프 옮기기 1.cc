#include <iostream>
using namespace std;

// y, x, 들어온 유형(가로, 세로, 대각선)
int dp[17][17][3]{};

bool isWall[17][17]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> isWall[i][j];

	dp[1][2][0] = 1;

	for (int i = 1; i <= n; ++i)
		for (int j = 3; j <= n; ++j)
		{
			if (isWall[i][j])
				continue;

			if (!isWall[i - 1][j] && !isWall[i][j - 1])
				dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];

			dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
			dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];
		}

	cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];

	return 0;
}
