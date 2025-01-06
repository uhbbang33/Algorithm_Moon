#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	vector<int> entryCnt(n + 1);
	vector<vector<int>> inputVec(n + 1);

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;

		inputVec[a].push_back(b);
		++entryCnt[b];
	}

	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (entryCnt[i] == 0) {
			cout << i << " ";
			q.push(i);
		}
	}

	while (!q.empty()) {
		for (int i = 0; i < inputVec[q.front()].size(); ++i) {
			int cur = inputVec[q.front()][i];

			if (entryCnt[cur] == 0)
				continue;

			if (--entryCnt[cur] == 0) {
				q.push(cur);
				cout << cur << " ";
			}
		}
		q.pop();
	}

	return 0;
}