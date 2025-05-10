#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<pair<int, int>> pq;
	for (int i = 1; i <= 8; ++i) {
		int score = 0;
		cin >> score;

		pq.push({ score, i });
	}

	priority_queue<int, vector<int>, greater<>> q;
	int sum = 0;
	for (int i = 0; i < 5; ++i) {
		sum += pq.top().first;
		q.push(pq.top().second);

		pq.pop();
	}
	
	cout << sum << "\n";
	while (!q.empty()) {
		cout << q.top() << " ";
		q.pop();
	}

	return 0;
}