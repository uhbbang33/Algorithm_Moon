#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	priority_queue<pair<int, bool>, vector<pair<int, bool>>, greater<pair<int, bool>>> pq;

	int x = 0;
	for (int i = 0; i < n; ++i) {
		cin >> x;

		if (x == 0) {
			if (!pq.empty()) {
				if(!pq.top().second)
					cout << -pq.top().first << "\n";
				else
					cout << pq.top().first << "\n";
				pq.pop();
			}
			else
				cout << "0\n";
			continue;
		}

		if (x < 0)
			pq.push(make_pair(-x, false));
		else
			pq.push(make_pair(x, true));
	}

	return 0;
}