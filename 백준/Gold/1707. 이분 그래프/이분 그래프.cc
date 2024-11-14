#include <iostream>
#include <vector>
using namespace std;

vector<int> edge[20001]{};
bool visited[20001]{};
int level[20001]{};
bool result = true;

void DFS(int vertex, int curLevel) {
	visited[vertex] = true;

	for (int i = 0; i < edge[vertex].size(); ++i) {
		int curVertex = edge[vertex][i];

		if (visited[curVertex]) {
			if (level[curVertex] == curLevel
				|| level[curVertex] % 2 == (curLevel - 1) % 2) {
				result = false;
				return;
			}
			continue;
		}

		visited[curVertex] = true;
		level[curVertex] = curLevel;

		DFS(curVertex, curLevel + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int k;
	cin >> k;

	while (k--) {
		int v, e;
		cin >> v >> e;

		for (int i = 1; i <= v; ++i) 
			edge[i].clear();

		for (int i = 0; i < e; ++i) {
			int a, b;
			cin >> a >> b;

			edge[a].push_back(b);
			edge[b].push_back(a);
		}

		for (int i = 1; i <= v; ++i) {
			visited[i] = false;
			level[i] = 0;
		}

		result = true;
		for (int i = 1; i <= v; ++i)
			if (!visited[i]) 
				DFS(i, 1);

		if (result) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}

	return 0;
}