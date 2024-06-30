#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end());

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < v.size(); ++i) {
		pq.push(v[i].second);
		if (pq.top() <= v[i].first)
			pq.pop();
	}

	cout << pq.size();

	return 0;
}