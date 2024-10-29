#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, c;
	cin >> n >> c;
	
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());

	int maxDist = 0;
	int start = 1, end = v[n - 1] - v[0];
	while (start <= end) {
		int mid = (start + end) / 2;

		int curSet = 1;
		int prev = v[0];
		for (int i = 0; i < n; ++i) {
			if (v[i] - prev >= mid) {
				++curSet;
				prev = v[i];
			}
		}

		if (curSet >= c) {
			maxDist = max(maxDist, mid);
			start = mid + 1;
		}
		else
			end = mid - 1;
	}

	cout << maxDist;

	return 0;
}