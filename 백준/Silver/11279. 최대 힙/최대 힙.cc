#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	priority_queue<int> pq;

	int x = 0;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		if (x == 0) {
			if (!pq.empty()) {
				cout << pq.top() << "\n";
				pq.pop();
			}
			else
				cout << "0\n";
		}
		else
			pq.push(x);
	}
	
	return 0;
}