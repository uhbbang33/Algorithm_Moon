#include <iostream>
using namespace std;

int n, m;
int visited[501][501]{};
int arr[501][501]{};
int maxResult = 0;

const int dy[4] = { 1, -1, 0, 0 };
const int dx[4] = { 0, 0, -1, 1 };
const int tetrominoSize = 4;

void Func(int y, int x, int cur) {
	for (int i = 0; i < 4; ++i) {
		int curResult = cur;

		for (int j = 0; j < 4; ++j) {
			if (j != i) {
				int ny = dy[j] + y;
				int nx = dx[j] + x;

				if (ny < 0 || nx < 0 || ny >= n || nx >= m)
					break;

				curResult += arr[ny][nx];
			}
		}
		maxResult = max(maxResult, curResult);
	}
}

void DFS(int y, int x, int cnt, int curResult) {	
	if (cnt == tetrominoSize) {
		maxResult = max(maxResult, curResult);
		return;
	}

	for (int i = 0; i < 4; ++i) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (ny < 0 || nx < 0 || ny >= n || nx >= m
			|| visited[ny][nx])
			continue;
		
		visited[ny][nx] = true;
		DFS(ny, nx, cnt + 1, curResult + arr[ny][nx]);
		visited[ny][nx] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j) 
			cin >> arr[i][j];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			Func(i, j, arr[i][j]);
			
			visited[i][j] = true;
			DFS(i, j, 1, arr[i][j]);
			visited[i][j] = false;
		}

	cout << maxResult;

	return 0;
}