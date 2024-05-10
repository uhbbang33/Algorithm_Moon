#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, k = 0;
	cin >> n >> k;
	cout << "<";

	queue<int> q;
	for (int i = 1; i < n + 1; ++i)
		q.push(i);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k - 1; ++j) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();

		if (i != n - 1)
			cout << ", ";
	}
	cout << ">";

	return 0;
}