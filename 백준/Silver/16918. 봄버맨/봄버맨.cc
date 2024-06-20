#include <iostream>
#include <queue>
#include <set>

using namespace std;

char graph[201][201]{};
char tempGraph[201][201]{};
int r, c, n = 0;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void BFS(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a, b });

	tempGraph[a][b] = '.';

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = a + dy[i];
			int nx = b + dx[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c)
				continue;

			if (graph[ny][nx] == 'O' && tempGraph[ny][nx] != '.')
				q.push({ ny, nx });

			tempGraph[ny][nx] = '.';
		}
	}
}

void GraphBFS() {
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			if (graph[i][j] == 'O')
				BFS(i, j);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c >> n;

	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j) {
			cin >> graph[i][j];
			tempGraph[i][j] = 'O';
		}

	if (n == 1) {
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j)
				cout << graph[i][j];
			cout << "\n";
		}
	}
	else if (n % 2 == 0) {
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j)
				cout << "O";
			cout << "\n";
		}
	}
	else {
		GraphBFS();

		if (n % 4 == 1) {
			for (int i = 0; i < r; ++i)
				for (int j = 0; j < c; ++j) {
					graph[i][j] = tempGraph[i][j];
					tempGraph[i][j] = 'O';
				}
			GraphBFS();
		}

		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j)
				cout << tempGraph[i][j];
			cout << "\n";
		}
	}

	return 0;
}