#include <iostream>
#include <queue>
#include <set>

using namespace std;

int n = 0;
char graph[26][26]{};
bool visited[26][26]{};

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

int BFS(int y, int x) {
	visited[y][x] = true;

	queue<pair<int, int>> q;
	q.push({ y, x });

	int cnt = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				continue;
			if (visited[ny][nx] || graph[ny][nx] != '1')
				continue;

			q.push({ ny, nx });
			visited[ny][nx] = true;
			++cnt;
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) 
			cin >> graph[i][j];

	multiset<int> result;
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j) 
			if (!visited[i][j] && graph[i][j] == '1') 
				result.insert(BFS(i, j));
	
	cout << result.size() << "\n";
	for (int a : result)
		cout << a << "\n";

	return 0;
}