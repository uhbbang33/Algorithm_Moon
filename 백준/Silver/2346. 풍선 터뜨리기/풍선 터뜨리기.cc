#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	deque<pair<int, int>> d(n);
	for (int i = 0; i < n; ++i) {
		cin >> d[i].first;
		d[i].second = i + 1;
	}

	for (int i = 0; i < n - 1; ++i) {
		cout << d.front().second << " ";

		int temp = d.front().first;
		d.pop_front();

		if (temp < 0) {
			while (temp < 0) {
				d.push_front(d.back());
				d.pop_back();
				++temp;
			}
		}
		else {
			temp -= 1;
			while (temp--) {
				d.push_back(d.front());
				d.pop_front();
			}
		}
	}

	cout << d.front().second;

	return 0;
}