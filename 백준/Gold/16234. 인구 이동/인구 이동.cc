#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, l, r;
int arr[51][51]{};
int visited[51][51]{};
int dayCnt = 0;
int curCnt = -1;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void BFS(int y, int x) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> unionVec;

	q.push({ y,x });
	unionVec.push_back({ y,x });
	visited[y][x] = dayCnt;

	int sum = 0;
	sum += arr[y][x];

	while (!q.empty()) {
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = curY + dy[i];
			int nx = curX + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n
				|| visited[ny][nx] == dayCnt)
				continue;

			int diff = abs(arr[ny][nx] - arr[curY][curX]);
			if (diff < l || r < diff)
				continue;

			visited[ny][nx] = dayCnt;
			q.push({ ny, nx });
			sum += arr[ny][nx];
			unionVec.push_back({ ny,nx });
		}
	}

	if (unionVec.size() > 1) {
		int aver = sum / unionVec.size();

		for (auto cur : unionVec)
			arr[cur.first][cur.second] = aver;

		++curCnt;
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
		++dayCnt;
		curCnt = 0;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (visited[i][j] != dayCnt)
					BFS(i, j);
	}

	cout << dayCnt - 1;

	return 0;
}
