#include <iostream>
#include <queue>
#include <functional>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	priority_queue<int, vector<int>, greater<int>> pq;
	int num = 0;
	for (int i = 0; i < n * n; ++i) {
		cin >> num;
		if (pq.size() >= n) {
			if (pq.top() < num) {
				pq.pop();
				pq.push(num);
			}
		}
		else
			pq.push(num);
	}

	cout << pq.top();

	return 0;
}