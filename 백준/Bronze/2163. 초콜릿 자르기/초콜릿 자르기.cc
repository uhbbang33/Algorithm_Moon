#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int> pq;
	int result = 0;

	int n, m;
	cin >> n >> m;
	pq.push(n * m);

	while (pq.top() != 1) {
		int temp = pq.top();
		pq.pop();

		if (temp % 2 == 1) {
			++result;
		}

		temp /= 2;
		pq.push(temp);
		pq.push(temp);

		++result;
	}
	
	cout << result;

	return 0;
}