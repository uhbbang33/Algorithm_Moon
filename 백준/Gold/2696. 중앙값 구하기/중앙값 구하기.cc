#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int m;
		cin >> m;

		priority_queue<int> pq;
		priority_queue<int, vector<int>, greater<int>> pqGreater;

		vector<int> result;

		for (int i = 1; i <= m; ++i) {
			int a;
			cin >> a;

			pq.push(a);

			if (!pqGreater.empty()
				&& pq.top() > pqGreater.top()) {
				pqGreater.push(pq.top());
				pq.pop();
			}

			if (pq.size() < pqGreater.size()) {
				pq.push(pqGreater.top());
				pqGreater.pop();
			}
			else if (pq.size() > pqGreater.size() + 1) {
				pqGreater.push(pq.top());
				pq.pop();
			}

			if (i % 2 == 1)
				result.push_back(pq.top());
		}

		cout << result.size() << "\n";
		for (int i = 0; i < result.size(); ++i) {
			cout << result[i] << " ";

			if ((i+1) % 10 == 0)
				cout << "\n";
		}
		cout << "\n";
	}

	return 0;
}