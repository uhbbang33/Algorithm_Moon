#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, h, t;
	cin >> n >> h >> t;

	priority_queue<int> pq;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		pq.push(x);
	}

	int cnt = 0;

	if (pq.top() < h) {
		cout << "YES" << "\n" << cnt;
		return 0;
	}

	while (t--) {
		int temp = pq.top();
		pq.pop();

		temp /= 2;
		if (temp < 1)
			temp = 1;
		pq.push(temp);

		++cnt;

		if (pq.top() < h) {
			cout << "YES" << "\n" << cnt;
			return 0;
		}
	}

	cout << "NO" << "\n" << pq.top();

	return 0;
}