#include <iostream>
using namespace std;

int m, n;

int dp[501][501]{};
int board[501][501]{};

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int DFS(int y, int x) {
	if (y == m - 1 && x == n - 1)
		return 1;

	if (dp[y][x] != -1)
		return dp[y][x];

	dp[y][x] = 0;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= m || nx < 0 || nx >= n)
			continue;

		if (board[y][x] > board[ny][nx])
			dp[y][x] += DFS(ny, nx);
	}

	return dp[y][x];
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;

	for (int i = 0; i < m; ++i) 
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
			dp[i][j] = -1;
		}

	cout << DFS(0, 0);

	return 0;
}
