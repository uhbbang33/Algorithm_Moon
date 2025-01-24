#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	queue<int> q;
	int sum = 0;
	int maxResult = -10000000;

	for (int i = 0; i < n; ++i) {
		int degree;
		cin >> degree;

		if (i == 0)
			sum = degree;
		else
			sum += degree;

		q.push(degree);
		if (q.size() > k) {
			sum -= q.front();
			q.pop();	
		}

		if (q.size() == k)
			maxResult = max(maxResult, sum);
	}
	cout << maxResult;

	return 0;
}
