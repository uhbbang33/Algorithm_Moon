#include <iostream>
#include <queue>

using namespace std;

bool arr[51][51]{};
bool visited[51][51]{};

int dy[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void BFS(int startY, int startX, int w, int h) {
	queue<pair<int, int>> q;
	q.push({ startY, startX });

	visited[startY][startX] = true;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;

		q.pop();
		
		for (int i = 0; i < 8; ++i) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;

			if (ny < 0 || nx < 0 || ny >= h || nx >= w)
				continue;

			if (visited[ny][nx])
				continue;

			visited[ny][nx] = true;
			
			if (arr[ny][nx] == 1)
				q.push({ ny, nx });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int w = -1, h = -1;

	while (1) {
		int result = 0;
		cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j) {
				cin >> arr[i][j];
				visited[i][j] = false;
			}

		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				if (arr[i][j] == 1 && !visited[i][j]) {
					BFS(i, j, w, h);
					++result;
				}

		cout << result << "\n";
	}

	return 0;
}