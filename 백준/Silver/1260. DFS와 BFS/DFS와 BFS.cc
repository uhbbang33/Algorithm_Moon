#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// n: 정점의 개수, m: 간선의 개수
// v: 탐색을 시작할 정점의 번호
int n, m, v;
bool visited[1001];
pair<int, int> line[10001];

void dfs(int x) {
	visited[x] = true;
	cout << x << ' ';
	
	for (int i = 0; i < m; ++i) {
		if (x == line[i].first && !visited[line[i].second])
			dfs(line[i].second);
		else if (x == line[i].second && !visited[line[i].first])
			dfs(line[i].first);
	}
}

void bfs(int x) {
	queue<int> q;
	q.push(x);

	visited[x] = true;

	while (!q.empty()) {
		int a = q.front();
		cout << a << ' ';

		q.pop();

		for (int i = 0; i < m; ++i) {
			if (a == line[i].first && !visited[line[i].second]) {
				q.push(line[i].second);
				visited[line[i].second] = true;
			}
			else if (a == line[i].second && !visited[line[i].first]) {
				q.push(line[i].first);
				visited[line[i].first] = true;
			}
		}
	}
}

int main() {
	cin >> n >> m >> v;

	for (int i = 0; i < m; ++i) {
		cin >> line[i].first >> line[i].second;
		if (line[i].first > line[i].second)
			swap(line[i].first, line[i].second);
	}
	sort(line, line + m);
	
	dfs(v);
	cout << endl;
	for (int i = 0; i <= n; ++i)
		visited[i] = false;
	bfs(v);

	return 0;
}