#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 0;
	cin >> t;

	while (--t >= 0) {
		int k = 0;
		cin >> k;

		priority_queue<long long, vector<long long>, greater<>> pq;

		int chapter = 0;
		for (int i = 0; i < k; ++i) {
			cin >> chapter;
			pq.push(chapter);
		}

		long long result = 0;
		for (int i = 0; i < k - 1; ++i) {
			long long temp = pq.top();
			pq.pop();
			temp += pq.top();
			pq.pop();

			pq.push(temp);
			result += temp;
		}

		cout << result << "\n";
	}

	return 0;
}