#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int> pq;
	cin.ignore();

	for (int i = 0; i < n; ++i) {
		int a = 0;
		cin >> a;

		if (a == 0) {
			if (!pq.empty()) {
				cout << pq.top() << "\n";
				pq.pop();
			}
			else
				cout << "-1" << "\n";
			
			continue;
		}

		for (int j = 0; j < a; ++j) {
			int x = 0;
			cin >> x;
			pq.push(x);
		}
	}

	return 0;
}