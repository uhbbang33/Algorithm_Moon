#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool visited[101]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, b, m;
	cin >> n >> a >> b >> m;

	vector<vector<int>> v(n + 1);

	for (int i = 0; i < m; ++i) {
		int p, c;
		cin >> p >> c;

		v[p].push_back(c);
		v[c].push_back(p);
	}

	queue<int> q;
	q.push(a);
	visited[a] = true;

	int result = 0;
	int cycleSize = q.size();

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == b) {
			cout << result;
			return 0;
		}

		for (auto temp : v[cur]) {
			if (!visited[temp]) {
				q.push(temp);
				visited[temp] = true;
			}
		}

		if (--cycleSize == 0) {
			++result;
			cycleSize = q.size();
		}
	}
	
	cout << "-1";

	return 0;
}