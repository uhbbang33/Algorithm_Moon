#include <iostream>
#include <queue>
using namespace std;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int n, m;
char board[51][51]{};

int Func(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a, b });

	bool visit[51][51]{};
	visit[a][b] = true;

	int dp[51][51]{};
	
	int moveCnt = 0;
	
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;

			if (ny < 0 || nx < 0 || ny >= n || nx >= m
				|| visit[ny][nx] || board[ny][nx] != 'L')
				continue;

			visit[ny][nx] = true;
			dp[ny][nx] = dp[y][x] + 1;
			moveCnt = max(moveCnt, dp[ny][nx]);
			q.push({ ny, nx });
		}
	}

	return moveCnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j) 
			cin >> board[i][j];

	int result = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (board[i][j] == 'L')
				result = max(result, Func(i, j));

	cout << result;

	return 0;
}