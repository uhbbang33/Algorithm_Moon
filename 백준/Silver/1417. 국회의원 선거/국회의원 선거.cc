#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int dasom = 0;
	cin >> dasom;
	if (n == 1) {
		cout << "0" << "\n";
		return 0;
	}

	priority_queue<int> pq;

	for (int i = 0; i < n-1; ++i) {
		int x;
		cin >> x;
		pq.push(x);
	}

	int result = 0;
	while (pq.top() >= dasom) {
		int temp = pq.top();
		pq.pop();

		--temp;
		pq.push(temp);

		++result;
		++dasom;
	}

	cout << result;

	return 0;
}