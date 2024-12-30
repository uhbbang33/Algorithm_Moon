#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int m, n, k;
bool isVisited[101][101]{};
vector<int> resultVec;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void BFS(int startY, int startX) {
	isVisited[startY][startX] = true;

	queue<pair<int, int>> q;
	q.push({ startY, startX });

	int cnt = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;

			if (ny < 0 || ny >= m || nx < 0 || nx >= n
				|| isVisited[ny][nx])
				continue;

			isVisited[ny][nx] = true;
			q.push({ ny, nx });
			++cnt;
		}
	}

	resultVec.push_back(cnt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n >> k;

	for (int i = 0; i < k; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = y1; i < y2; ++i) 
			for (int j = x1; j < x2; ++j) 
				isVisited[i][j] = true;
	}

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (!isVisited[i][j])
				BFS(i, j);

	sort(resultVec.begin(), resultVec.end());

	cout << resultVec.size() << "\n";

	for (int result : resultVec)
		cout << result << " ";

	return 0;
}