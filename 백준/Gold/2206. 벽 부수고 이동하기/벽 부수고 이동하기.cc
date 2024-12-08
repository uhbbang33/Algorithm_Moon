#include <iostream>
#include <queue>
using namespace std;

int n, m;
char arr[1001][1001]{};
bool visited[1001][1001]{};
bool breakVisited[1001][1001]{};

int BFS(int startY, int startX) {
	if (startY == n - 1 && startX == m - 1)
		return 1;

	queue<pair<pair<int, int>, bool>> q; // bool - 벽을 부쉈는지 여부
	q.push({ {startY, startX}, 0 });

	visited[startY][startX] = true;
	breakVisited[startY][startX] = true;

	int dy[4] = { 1, -1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };
	int cnt = 0;
	int cycleSize = 0;

	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		bool isBreakWall = q.front().second;

		if (cycleSize == 0) {
			++cnt;
			cycleSize = q.size();
		}

		q.pop();
		--cycleSize;

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			if ((isBreakWall && breakVisited[ny][nx])
				|| (!isBreakWall && visited[ny][nx]))
				continue;

			if (ny == n - 1 && nx == m - 1)
				return cnt + 1;

			if (isBreakWall)
				breakVisited[ny][nx] = true;
			else
				visited[ny][nx] = true;

			if (arr[ny][nx] == '1' && !isBreakWall)
				q.push({ {ny, nx}, 1 });
			else if (arr[ny][nx] == '0') {
				if (!isBreakWall)
					q.push({ {ny,nx}, 0 });
				else
					q.push({ {ny,nx}, 1 });
			}
		}
	}
	return -1;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j)
			cin >> arr[i][j];

	cout << BFS(0, 0);

	return 0;
}