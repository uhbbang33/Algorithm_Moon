#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	int maxPrev[3]{};
	int minPrev[3]{};
	int maxCur[3]{};
	int minCur[3]{};
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> maxCur[j];
			minCur[j] = maxCur[j];
		}

		maxCur[0] += max(maxPrev[0], maxPrev[1]);
		maxCur[1] += max(max(maxPrev[0], maxPrev[1]), maxPrev[2]);
		maxCur[2] += max(maxPrev[1], maxPrev[2]);

		minCur[0] += min(minPrev[0], minPrev[1]);
		minCur[1] += min(min(minPrev[0], minPrev[1]), minPrev[2]);
		minCur[2] += min(minPrev[1], minPrev[2]);

		swap(maxCur, maxPrev);
		swap(minCur, minPrev);
	}
	

	cout << max(max(maxPrev[0], maxPrev[1]), maxPrev[2]) << " "
		<< min(min(minPrev[0], minPrev[1]), minPrev[2]);

	return 0;
}
