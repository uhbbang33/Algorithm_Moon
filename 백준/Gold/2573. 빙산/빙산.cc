#include <iostream>
#include <queue>
using namespace std;

int n, m;
int board[301][301]{};
bool visited[301][301]{};

int dy[4]{ 1,-1,0,0 };
int dx[4]{ 0,0,-1,1 };

void Melt(int startY, int startX) {
	queue<pair<int, int>> q;
	q.push({ startY,startX });

	visited[startY][startX] = true;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;

			if (ny < 0 || nx < 0 || ny >= n || nx >= m
				|| visited[ny][nx])
				continue;

			if (board[ny][nx] == 0)
				--board[y][x];
			else {
				q.push({ ny,nx });
				visited[ny][nx] = true;
			}
		}

		if (board[y][x] < 0)
			board[y][x] = 0;
	}
}

int CountMountain() {
	int cnt = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (board[i][j] > 0 && !visited[i][j]) {
				Melt(i, j);
				++cnt;
			}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];

	int minYear = 0;
	int cnt = -1;

	while (true) {
		cnt = CountMountain();

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				visited[i][j] = false;

		if (cnt == 0) {
			minYear = 0;
			break;
		}
		
		if (cnt != 1)
			break;

		++minYear;
	}

	cout << minYear;

	return 0;
}