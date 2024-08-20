#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, a, b;
	cin >> t;

	while (--t >= 0) {
		cin >> a >> b;

		queue<int> q;

		int temp = a;
		for (int i = 2; i * i <= a; ++i) {
			while (temp % i == 0) {
				temp /= i;
				q.push(i);
			}
		}
		q.push(temp);

		queue<int> tempQ = q;
		while (!tempQ.empty()) {
			if (b % tempQ.front() == 0)
				b /= tempQ.front();
			tempQ.pop();
		}
		q.push(b);

		int result = 1;
		while (!q.empty()) {
			result *= q.front();
			q.pop();
		}
		
		cout << result << "\n";
		
	}

	return 0;
}