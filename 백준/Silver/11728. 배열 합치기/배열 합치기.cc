#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	priority_queue<int, vector<int>, greater<>> pq;
	
	int num;
	for (int i = 0; i < n+m; ++i) {
		cin >> num;
		pq.push(num);
	}

	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}

	return 0;
}