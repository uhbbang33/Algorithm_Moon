#include <iostream>
#include <stack>
using namespace std;

int n, m;
char graph[501][501]{};
int visited[501][501]{};
stack<pair<int, int>> s;

void Func(int startY, int startX) {
	s.push({ startY, startX });
	visited[startY][startX] = 2;
	
	while (!s.empty()) {
		int y = s.top().first;
		int x = s.top().second;
		char cur = graph[y][x];
		visited[y][x] = 2;
		
		if (cur == 'U') --y;
		else if (cur == 'R') ++x;
		else if (cur == 'L') --x;
		else if (cur == 'D') ++y;

		if (x < 0 || x >= m || y < 0 || y >= n || visited[y][x] == 1) {
			while (!s.empty()) {
				visited[s.top().first][s.top().second] = 1;
				s.pop();
			}
			break;
		}
		
		if (visited[y][x] == 2) {
			while (!s.empty()) {
				visited[s.top().first][s.top().second] = 2;
				s.pop();
			}
			break;
		}

		s.push({ y,x });
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j) 
			cin >> graph[i][j];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (visited[i][j] == 0)
				Func(i, j);

	int result = 0;
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j) 
			if (visited[i][j] == 1)
				++result;

	cout << result;

	return 0;
}