#include <iostream>
#include <queue>
using namespace std;

int board[101][101]{};
unsigned long long dp[110][110]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j) 
			cin >> board[i][j];

	dp[0][0] = 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if (dp[i][j] == 0 || (i == n - 1 && j == n - 1))
				continue;
			
			dp[board[i][j] + i][j] += dp[i][j];
			dp[i][board[i][j] + j] += dp[i][j];
		}

	
	cout << dp[n - 1][n - 1];

	return 0;
}