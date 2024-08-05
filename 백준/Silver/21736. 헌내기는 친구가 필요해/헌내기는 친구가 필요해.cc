#include <iostream>
#include <queue>
using namespace std;

char info[601][601]{};
bool visited[601][601]{};

int n, m;
int result = 0;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void BFS(int doyeonY, int doyeonX) {
	visited[doyeonY][doyeonX] = true;
	
	queue<pair<int, int>> q;
	q.push({ doyeonY, doyeonX });

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;

		for (int i = 0; i < 4; ++i) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;

			if (ny >= n || nx >= m || nx < 0 || ny < 0)
				continue;
			if (info[ny][nx] == 'X' || visited[ny][nx])
				continue;

			if (info[ny][nx] == 'P')
				++result;

			visited[ny][nx] = true;
			q.push({ ny, nx });
		}
		q.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	int doyeonX = 0, doyeonY = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> info[i][j];
			if (info[i][j] == 'I') {
				doyeonY = i;
				doyeonX = j;
			}
		}
	}

	BFS(doyeonY, doyeonX);

	if (result == 0)
		cout << "TT";
	else
		cout << result;

	return 0;
}