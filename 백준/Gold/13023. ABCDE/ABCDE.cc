#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;

bool visited[2001]{};
bool possible = false;

void DFS(int node, int cnt) {
	if (cnt == 5) {
		possible = true;
		return;
	}

	visited[node] = true;

	for (int i = 0; i < v[node].size(); ++i) {
		int next = v[node][i];

		if (!visited[next]) {
			DFS(next, cnt + 1);

			visited[next] = false;
		}
	}
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

		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			DFS(i, 1);
			visited[i] = false;
		}

		if (possible) {
			cout << "1";
			return 0;
		}
	}

	cout << "0";

	return 0;
}