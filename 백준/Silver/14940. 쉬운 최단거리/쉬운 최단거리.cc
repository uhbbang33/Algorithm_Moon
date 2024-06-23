#include <iostream>
#include <queue>

using namespace std;

int n, m;
int graph[1001][1001]{};
int result[1001][1001]{};

int dy[4] = { 0, 0 , -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

void BFS(int y, int x) {
	result[y][x] = 0;

	queue<pair<int, int>> q;
	q.push({ y, x });

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;

		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = a + dy[i];
			int nx = b + dx[i];

			if (ny < 0 || nx < 0 || ny > n || nx > m
				|| result[ny][nx] != -1)
				continue;

			result[ny][nx] = result[a][b] + 1;

			q.push({ ny, nx });
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	
	int tempY = 0, tempX = 0;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> graph[i][j];
			
			result[i][j] = -1;

			if (graph[i][j] == 0)
				result[i][j] = 0;
			else if (graph[i][j] == 2) {
				tempY = i;
				tempX = j;
			}
		}

	BFS(tempY, tempX);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << result[i][j] << " ";

		cout << "\n";
	}

	return 0;
}