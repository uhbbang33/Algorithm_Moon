#include <iostream>
using namespace std;

int n, m, d;
int arr[51][51]{};
bool visited[51][51]{};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int Func(int startY, int startX) {
	visited[startY][startX] = true;

	int y = startY;
	int x = startX;
	int cnt = 1;

	while (1) {
		bool isClean = false;
		int curdir = d;

		for (int i = 0; i < 4; ++i) {
			d = (d + 1) % 4;

			int ny = dy[d] + y;
			int nx = dx[d] + x;

			if (ny < 0 || nx < 0 || ny >= n || nx >= m
				|| arr[ny][nx] == 1 || visited[ny][nx])
				continue;

			isClean = true;
			visited[ny][nx] = true;

			y = ny;
			x = nx;
			++cnt;

			break;
		}

		if (isClean)
			continue;

		int tempDir = (curdir + 2) % 4;
		int ny = dy[tempDir] + y;
		int nx = dx[tempDir] + x;

		if (ny < 0 || nx < 0 || ny >= n || nx >= m
			|| arr[ny][nx] == 1)
			break;

		y = ny;
		x = nx;
		d = curdir;
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int r, c;
	cin >> n >> m >> r >> c >> d;
	if (d == 1) d = 3;
	else if (d == 3) d = 1;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> arr[i][j];

	cout << Func(r, c);

	return 0;
}