#include <iostream>
#include <queue>
using namespace std;

int n;
int arr[101][101]{};
bool visited[101][101]{};

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void BFS(int y, int x, int height) {
	queue<pair<int, int>> q;
	q.push({ y,x });

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = a + dy[i];
			int nx = b + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n
				|| visited[ny][nx])
				continue;

			if (arr[ny][nx] > height)
				q.push({ ny, nx });

			visited[ny][nx] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	int maxHeight = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
			maxHeight = max(maxHeight, arr[i][j]);
		}

	int maxResult = 0;
	for (int k = 0; k <= maxHeight; ++k) {
		int tempResult = 0;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				visited[i][j] = false;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) 
				if (arr[i][j] > k && !visited[i][j]) {
					BFS(i, j, k);
					++tempResult;
				}

		maxResult = max(tempResult, maxResult);
	}

	cout << maxResult;

	return 0;
}