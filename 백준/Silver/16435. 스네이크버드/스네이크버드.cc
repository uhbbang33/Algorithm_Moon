#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l;
	cin >> n >> l;

	priority_queue<int, vector<int>, greater<>> pq;

	for (int i = 0; i < n; ++i) {
		int h;
		cin >> h;

		pq.push(h);
	}

	while (!pq.empty()) {
		if (pq.top() <= l) {
			++l;
			pq.pop();
		}
		else break;
	}

	cout << l;


	return 0;
}