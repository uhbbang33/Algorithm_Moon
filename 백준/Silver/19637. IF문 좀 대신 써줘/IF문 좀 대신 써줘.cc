#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<string> title;
vector<int> attackRange;

void BinarySearch(int start, int end, int target) {
	int mid = 0;

	while (start <= end) {
		mid = (start + end) / 2;

		if (target <= attackRange[mid])
			end = mid - 1;
		if (target > attackRange[mid])
			start = mid + 1;
	}

	if (target > attackRange[mid])
		cout << title[mid + 1] << "\n";
	else
		cout << title[mid] << "\n";

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	
	title.resize(n);
	attackRange.resize(n);


	for (int i = 0; i < n; ++i) {
		cin >> title[i] >> attackRange[i];
	}

	int attack;
	for (int i = 0; i < m; ++i) {
		cin >> attack;
		BinarySearch(0, n - 1, attack);
	}

	return 0;
}