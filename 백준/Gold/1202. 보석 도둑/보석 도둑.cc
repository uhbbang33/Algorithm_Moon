#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> jewel(n);
	for (int i = 0; i < n; ++i)
		cin >> jewel[i].first >> jewel[i].second;
	sort(jewel.begin(), jewel.end());

	vector<int> bag(k);
	for (int i = 0; i < k; ++i)
		cin >> bag[i];
	sort(bag.begin(), bag.end());

	priority_queue<int> pq;
	long long result = 0;
	int index = 0;

	for (int i = 0; i < k; ++i) {
		while (index < n && jewel[index].first <= bag[i]) {
			pq.push(jewel[index].second);
			++index;
		}
		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
	}

	cout << result;

	return 0;
}