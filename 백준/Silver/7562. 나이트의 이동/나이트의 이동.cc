#include <iostream>
#include <queue>
using namespace std;

int l, curY, curX, targetY, targetX;
bool visited[301][301]{};
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int BFS() {
	queue<pair<int, int>> q;
	q.push({curY, curX});
	visited[curY][curX] = true;

	int cnt = 0;
	if (curY == targetY && curX == targetX)
		return cnt;

	int cycleSize = 0;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;

		if (cycleSize == 0) {
			++cnt;
			cycleSize = q.size();
		}
		q.pop();

		for (int i = 0; i < 8; ++i) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;

			if (ny > l || nx > l || ny < 0 || nx < 0
				|| visited[ny][nx])
				continue;

			if (ny == targetY && nx == targetX)
				return cnt;

			q.push({ ny, nx });
			visited[ny][nx] = true;
		}
		--cycleSize;
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		cin >> l >> curY >> curX >> targetY >> targetX;

		for (int i = 0; i < l; ++i) 
			for (int j = 0; j < l; ++j)
				visited[i][j] = false;
		
		cout << BFS() << "\n";
	}

	return 0;
}