#include <iostream>
#include <algorithm>
using namespace std;

int arr[501][501]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			cin >> arr[i][0];
			continue;
		}

		for (int j = 0; j <= i; ++j) {
			cin >> arr[i][j];

			if (j != 0 && j != i) {
				int bigNum = max(arr[i - 1][j - 1], arr[i - 1][j]);
				arr[i][j] += bigNum;
			}
			else if (j == 0)
				arr[i][j] += arr[i - 1][j];
			else if (j == i)
				arr[i][j] += arr[i - 1][j - 1];
		}
	}

	int result = 0;
	for (int i = 0; i < n; ++i)
		result = max(arr[n - 1][i], result);
	cout << result;

	return 0;
}