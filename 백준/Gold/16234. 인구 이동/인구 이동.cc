#include <iostream>
#include <queue>
using namespace std;

int n, l, r;
int arr[51][51]{};
bool visited[51][51]{};
int dayCnt = -1;
int curCnt = -1;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void BFS(int y, int x) {
	queue<pair<int, int>> q;
	int sum = 0;

	q.push({ y,x });
	visited[y][x] = true;
	sum += arr[y][x];

	queue<pair<int, int>> unionQueue;

	while (!q.empty()) {
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();
		
		unionQueue.push({ curY, curX });

		for (int i = 0; i < 4; ++i) {
			int ny = curY + dy[i];
			int nx = curX + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n
				|| visited[ny][nx])
				continue;

			int diff = abs(arr[ny][nx] - arr[curY][curX]);
			if (diff < l || r < diff)
				continue;

			visited[ny][nx] = true;
			q.push({ ny, nx });
			sum += arr[ny][nx];
			++curCnt;
		}
	}

	int aver = sum / unionQueue.size();
	while (!unionQueue.empty()) {
		arr[unionQueue.front().first][unionQueue.front().second] = aver;
		unionQueue.pop();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> l >> r;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) 
			cin >> arr[i][j];

	while (curCnt != 0) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				visited[i][j] = false;

		curCnt = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (!visited[i][j])
					BFS(i, j);

		++dayCnt;
	}

	cout << dayCnt;

	return 0;
}
