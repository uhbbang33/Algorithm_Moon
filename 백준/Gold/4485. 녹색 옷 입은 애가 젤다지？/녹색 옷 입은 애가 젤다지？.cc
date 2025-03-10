#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int>> myPair;

int n;
int board[126][126]{};
int visited[126][126]{};

int dy[4]{ 1,-1,0,0 };
int dx[4]{ 0,0,-1,1 };

int Dijkstra() {
	priority_queue<myPair, vector<myPair>, greater<>> pq;
	pq.push({ board[0][0], {0,0}});
	visited[0][0] = true;

	while (!pq.empty()) {
		int coin = pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx])
				continue;

			int nextCoin = coin + board[ny][nx];

			if (ny == n - 1 && nx == n - 1)
				return nextCoin;

			pq.push({ nextCoin, {ny, nx} });
			visited[ny][nx] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int cnt = 0;

	while (true) {
		++cnt;

		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; ++i) 
			for (int j = 0; j < n; ++j) {
				cin >> board[i][j];
				visited[i][j] = false;
			}

		cout << "Problem " << cnt << ": " << Dijkstra() << "\n";
	}

	return 0;
}