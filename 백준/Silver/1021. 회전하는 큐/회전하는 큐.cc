#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	deque<int> d(n);
	for (int i = 0; i < n; ++i)
		d[i] = i + 1;
	
	int cnt = 0;

	for (int i = 0; i < m; ++i) {
		int target = 0;
		cin >> target;

		if (d[0] == target) {
			d.pop_front();
			continue;
		}

		deque<int> tempDeque1 = d, tempDeque2 = d;
		int tempCnt1 = 0, tempCnt2 = 0;

		while (tempDeque1[0] != target) {
			tempDeque1.push_front(tempDeque1.back());
			tempDeque1.pop_back();
			++tempCnt1;
		}
		while (tempDeque2[0] != target) {
			tempDeque2.push_back(tempDeque2.front());
			tempDeque2.pop_front();
			++tempCnt2;
		}

		if (tempCnt1 < tempCnt2) {
			cnt += tempCnt1;
			d = tempDeque1;
		}
		else {
			cnt += tempCnt2;
			d = tempDeque2;
		}

		d.pop_front();
	}

	cout << cnt;

	return 0;
}