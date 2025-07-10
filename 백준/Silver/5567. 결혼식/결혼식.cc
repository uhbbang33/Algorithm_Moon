#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool visited[501]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n+1);
	
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int result = 0;

	queue<int> q;
	q.push(1);
	visited[1] = true;
	
	int qSize = q.size();
	int cnt = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); ++i) {
			int next = v[cur][i];

			if (visited[next])
				continue;
			
			q.push(next);
			++result;
			visited[next] = true;
		}
		--qSize;
		if (qSize == 0) {
			qSize = q.size();
			++cnt;

			if (cnt >= 2)
				break;
		}
	}

	cout << result;

	return 0;
}