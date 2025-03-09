#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int>> myPair;

int n, m;
int dy[4]{1, -1, 0, 0};
int dx[4]{0, 0, -1, 1};

vector<vector<char>> maze;
vector<vector<bool>> isVisited;

int Dijkstra() {
	// 부순 벽 개수, (y, x)
	priority_queue<myPair, vector<myPair>, greater<>> pq;
	pq.push({ 0,{0,0} });
	isVisited[0][0] = true;

	while (!pq.empty()) {
		int wall = pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || isVisited[ny][nx])
				continue;

			if (ny == n - 1 && nx == m - 1)
				return wall;

			if (maze[ny][nx] == '1')
				pq.push({ wall + 1, {ny, nx} });
			else
				pq.push({ wall, {ny, nx} });

			isVisited[ny][nx] = true;
		}
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;

	maze.resize(n);
	isVisited.resize(n);

	for (int i = 0; i < n; ++i) {
		maze[i].resize(m);
		isVisited[i].resize(m);

		for (int j = 0; j < m; ++j)
			cin >> maze[i][j];
	}
	
	cout << Dijkstra();

	return 0;
}