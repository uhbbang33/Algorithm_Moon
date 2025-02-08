#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

vector<set<int>> v;

int BFS(int idx) {
	queue<pair<int, int>> q;
	q.push({ idx, 0 });

	bool visited[101]{};
	visited[idx] = true;

	int totalCnt = 0;
	while (!q.empty()) {
		int curIdx = q.front().first;
		int curCnt = q.front().second;
		q.pop();
		
		for (int a : v[curIdx]) {
			if (visited[a])
				continue;

			visited[a] = true;
			q.push({ a, curCnt + 1 });
			totalCnt += curCnt + 1;
		}
	}

	return totalCnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	v.resize(n + 1);

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;

		v[a].insert(b);
		v[b].insert(a);
	}

	int minBacon = 100000;
	int resultPer = -1;

	for (int i = 1; i <= n; ++i) {
		int bfs = BFS(i);

		if (minBacon > bfs) {
			minBacon = bfs;
			resultPer = i;
		}
	}
	cout << resultPer;

	return 0;
}
