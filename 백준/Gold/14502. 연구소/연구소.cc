#include <iostream>
#include <queue>
using namespace std;

#define WAR_MAXCNT 3

int n = 0, m = 0;
int maxCnt = 0;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void BFS(int tempArr[9][9]) {
	queue<pair<int, int>> q;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (tempArr[i][j] == 2)
				q.push({ i, j });

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (nx >= m || nx < 0 || ny >= n || ny < 0)
				continue;

			if (tempArr[ny][nx] == 0) {
				tempArr[ny][nx] = 2;
				q.push({ ny, nx });
			}
		}
		q.pop();
	}
}

void combi(int startY, int startX, int arr[9][9], int warCnt)
{
	int copyArr[9][9]{};
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			copyArr[i][j] = arr[i][j];

	if (warCnt == WAR_MAXCNT) {
		BFS(copyArr);

		int safeCnt = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (copyArr[i][j] == 0)
					++safeCnt;

		maxCnt = max(safeCnt, maxCnt);
		return;
	}

	for (int i = startY; i < n; ++i) {
		for (int j = (i == startY ? startX : 0); j < m; ++j) {
			if (copyArr[i][j] == 0) {
				copyArr[i][j] = 1;
				combi(i, j, copyArr, warCnt + 1);
				copyArr[i][j] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	int arr[9][9]{};

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> arr[i][j];

	combi(0, 0, arr, 0);
	cout << maxCnt;

	return 0;
}