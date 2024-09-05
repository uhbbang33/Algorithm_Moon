#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	priority_queue<long long, vector<long long>, greater<>> pq;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		pq.push(num);
	}

	while (m--) {
		long long x = pq.top();
		pq.pop();
		long long y = pq.top();
		pq.pop();
		
		pq.push(x + y);
		pq.push(x + y);
	}

	long long result = 0;
	while(!pq.empty()){
		result += pq.top();
		pq.pop();
	}
	cout << result;

	return 0;
}