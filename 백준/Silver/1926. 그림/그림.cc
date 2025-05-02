#include <iostream>
#include <queue>
using namespace std;

int n, m;
int board[501][501]{};

int dy[4] = { 1, -1, 0,0 };
int dx[4] = { 0, 0, -1, 1 };

int BFS(int startY, int startX) {
	queue<pair<int, int>> q;
	q.push({ startY, startX });
	board[startY][startX] = 0;

	int artSize = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;

			if (ny < 0 || nx < 0 || ny >= n || nx >= m 
				|| board[ny][nx] == 0)
				continue;

			q.push({ ny, nx });
			board[ny][nx] = 0;
			++artSize;
		}
	}
	
	return artSize;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];

	int result = 0, maxSize = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) 
			if (board[i][j] == 1) {
				maxSize = max(maxSize, BFS(i, j));
				++result;
			}

	cout << result << "\n" << maxSize;

	return 0;
}