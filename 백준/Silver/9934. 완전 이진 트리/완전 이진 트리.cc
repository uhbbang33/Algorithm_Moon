#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int k = 0;
	cin >> k;

	vector<vector<int>> levels(k);

	int buildingNum = 0;
	for (int i = 1; i < pow(2, k); ++i) {
		cin >> buildingNum;

		if (i % 2 == 1) {
			levels[0].push_back(buildingNum);
			continue;
		}

		for (int j = 1; j < k; ++j) {
			int temp = pow(2, j + 1);

			if (i % temp == temp / 2) {
				levels[j].push_back(buildingNum);
				break;
			}
		}
	}

	for (int i = k - 1; i >= 0; --i) {
		for (int j = 0; j < levels[i].size(); ++j)
			cout << levels[i][j] << " ";
		cout << "\n";
	}

	return 0;
}