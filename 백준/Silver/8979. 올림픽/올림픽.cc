#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	priority_queue<pair<tuple<int, int, int>,int> > pq;

	for (int i = 0; i < n; ++i) {
		int c, g, s, d;
		cin >> c >> g >> s >> d;

		pq.push({ {g,s,d}, c });
	}

	int result = 0;
	int sameNum = 0;
	tuple<int, int, int> last;

	while (!pq.empty()) {
		if (last != pq.top().first) {
			result += sameNum + 1;
			sameNum = 0;
		}
		else
			++sameNum;

		if (pq.top().second == k)
			break;
		else {
			last = pq.top().first;
			pq.pop();
		}
	}

	cout << result;

	return 0;
}