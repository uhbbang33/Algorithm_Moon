#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int visited[1000001]{};
vector<vector<int>> vec;
int cnt = 0;

void DFS(int cur) {
	visited[cur] = ++cnt;

	for (int i = 0; i < vec[cur].size(); ++i) 
		if (visited[vec[cur][i]] == 0) 
			DFS(vec[cur][i]);
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

	for (int i = 0; i < n; ++i)
		sort(vec[i].begin(), vec[i].end());

	DFS(r);

	for (int i = 1; i <= n; ++i)
		cout << visited[i] << "\n";
	
	return 0;
}