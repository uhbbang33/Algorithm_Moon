#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

bool isStack[100001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> isStack[i];

	deque<int> dq;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (isStack[i] == 0)
			dq.push_back(x);
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;

		dq.push_front(x);
		cout << dq.back() << " ";
		dq.pop_back();
	}

	return 0;
}