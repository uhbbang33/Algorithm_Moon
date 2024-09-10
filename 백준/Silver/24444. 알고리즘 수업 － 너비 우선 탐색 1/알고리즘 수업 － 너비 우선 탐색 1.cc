#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[100001]{};
int order[100001]{};
vector<vector<int>> vec;

void BFS(int x) {
	queue<int> q;
	q.push(x);
	visited[x] = true;

	int orderCnt = 1;
	if (vec[x].size() == 0) {
		order[x] = orderCnt;
		return;
	}
	
	while (!q.empty()) {
		int f = q.front();

		for (int i = 0; i < vec[f].size(); ++i) {
			int cur = vec[f][i];
			if (!visited[cur]) {
				q.push(cur);
				visited[cur] = true;
			}
		}

		order[f] = orderCnt;
		++orderCnt;
		q.pop();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, r;
	cin >> n >> m >> r;
	vec.resize(n + 1);

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	
	for (int i = 1; i <= n; ++i)
		sort(vec[i].begin(), vec[i].end());

	BFS(r);

	for (int i = 1; i <= n; ++i)
		cout << order[i] << "\n";
	
	return 0;
}