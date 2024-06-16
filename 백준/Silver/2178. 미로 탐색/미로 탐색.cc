#include <iostream>
#include <queue>

using namespace std;

int n, m;
int graph[101][101];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			if (graph[nx][ny] == 0) continue;

			if (graph[nx][ny] == 1) {
				graph[nx][ny] = graph[a][b] + 1;
				q.push({ nx, ny });
			}
		}
	}
	return graph[n - 1][m - 1];
}

int main() {
	//ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%1d", &graph[i][j]);

	cout << bfs(0, 0);

	return 0;
}