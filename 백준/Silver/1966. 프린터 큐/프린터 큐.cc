#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 0, n = 0, m = 0;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		cin >> n >> m;

		queue<pair<int, int>> q;
		priority_queue<int> pq;
		int num = 0;

		for (int j = 0; j < n; ++j) {
			cin >> num;
			q.push(make_pair(num, j));
			pq.push(num);
		}

		int result = 0;
		while (!q.empty()) {
			if (pq.top() == q.front().first) {
				pq.pop();
				++result;
				if (q.front().second == m)
					break;
			}
			else
				q.push(q.front());
			q.pop();
		}
		cout << result << endl;
	}

	return 0;
}