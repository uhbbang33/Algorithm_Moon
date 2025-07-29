#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<vector<int>> v;

bool BFS(int start) {
	queue<pair<int, set<int>>> q;
	set<int> s{ start };

	q.push({ start, s});

	while (!q.empty()) {
		int cur = q.front().first;
		set<int> curSet = q.front().second;
		q.pop();
		
		for (int i = 0; i < v[cur].size(); ++i) {
			int next = v[cur][i];

			if (curSet.find(next) != curSet.end())
				continue;

			set<int> nextSet = curSet;
			nextSet.insert(next);

			q.push({ next, nextSet });

			if (nextSet.size() == 5)
				return true;
		}
	}

	return false;
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
		if (BFS(i)) {
			cout << "1";
			return 0;
		}
	}

	cout << "0";

	return 0;
}