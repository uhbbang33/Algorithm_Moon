#include <iostream>
#include <queue>

using namespace std;

int m, n;
int graph[1001][1001]{};
queue<pair<int, int>> q;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0 , 0 };

int BFS() {
	int a = 0, b = 0;
	while (!q.empty()) {
		a = q.front().first;
		b = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = a + dy[i];
			int nx = b + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m
				|| graph[ny][nx] == -1 || graph[ny][nx] == 1)
				continue;

			if (graph[ny][nx] == 0) {
				graph[ny][nx] = graph[a][b] + 1;
				q.push({ ny, nx });
			}
		}
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (graph[i][j] == 0)
				return -1;

	return graph[a][b] - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> graph[i][j];
			if (graph[i][j] == 1)
				q.push({ i, j });
		}

	cout << BFS();

	return 0;
}