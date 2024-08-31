#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> note1;

bool BinarySearch(int start, int end, int target) {
	while (start <= end) {
		int mid = (start + end) / 2;

		if (note1[mid] > target)
			start = mid + 1;
		else if (note1[mid] < target)
			end = mid - 1;
		else if (note1[mid] == target)
			return true;
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		
		note1.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> note1[i];
		sort(note1.begin(), note1.end(), greater<>());

		int m;
		cin >> m;

		int note2;
		for (int i = 0; i < m; ++i) {
			cin >> note2;
			cout << BinarySearch(0, n - 1, note2) << "\n";
		}
	}

	return 0;
}