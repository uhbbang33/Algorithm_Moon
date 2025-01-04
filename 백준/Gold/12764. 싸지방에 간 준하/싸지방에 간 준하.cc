#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>> timeVec;
	for (int i = 0; i < n; ++i) {
		int p, q;
		cin >> p >> q;
		
		timeVec.push_back({ p,q });
	}
	sort(timeVec.begin(), timeVec.end());


	// first: endTime, second: 자리
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
	// first: 자리, second: endTime
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> useCom;
	
	vector<int> cnt(n);
	int cur = 0;

	for (int i = 0; i < n; ++i) {
		while (!minHeap.empty()) {
			if (minHeap.top().first < timeVec[i].first) {
				useCom.push({ minHeap.top().second, minHeap.top().first});
				minHeap.pop();
			}
			else 
				break;
		}

		if (useCom.empty()) {
			++cnt[cur];
			minHeap.push({ timeVec[i].second, cur++ });
		}
		else {
			minHeap.push({ timeVec[i].second, useCom.top().first });
			++cnt[useCom.top().first];
			useCom.pop();
		}
	}

	cout << cur << "\n";

	for (int i = 0; i < cur; ++i) 
		cout << cnt[i] << " ";

	return 0;
}