#include <iostream>
#include <queue>
using namespace std;

int n, m;
int dy[4]{ 1, -1, 0, 0 };
int dx[4]{ 0, 0, -1, 1 };

bool board[101][101]{};

int BFS() {
	queue<pair<int, int>> q;
	q.push({ 0,0 });

	bool visited[101][101]{};
	visited[0][0] = true;

	int cnt = 0;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;

		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m
				|| visited[ny][nx])
				continue;

			visited[ny][nx] = true;

			if (board[ny][nx]) {
				board[ny][nx] = 0;
				++cnt;
			}
			else
				q.push({ ny, nx });
		}
	}
	
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];


	int cnt = 0;
	int last = 1;
	while (1) {
		int cheese = BFS();
		if (cheese != 0)
			last = cheese;
		else
			break;

		++cnt;
	}
	
	cout << cnt << "\n" << last;

	return 0;
}