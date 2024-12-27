#include <iostream>
using namespace std;

int dpGreater[1001]{};
int dpLess[1001]{};
int arr[1001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	for (int i = 0; i < n; ++i) {
		dpGreater[i] = 1;
		dpLess[n - i - 1] = 1;

		for (int j = 0; j < i; ++j) {
			if (arr[j] < arr[i])
				dpGreater[i] = max(dpGreater[i], dpGreater[j] + 1);

			if (arr[n - j - 1] < arr[n - i - 1])
				dpLess[n - i - 1] = max(dpLess[n - i - 1], dpLess[n - j - 1] + 1);
		}
	}
	
	int maxResult = 0;
	for (int i = 0; i < n; ++i)
		maxResult = max(maxResult, dpLess[i] + dpGreater[i] - 1);

	cout << maxResult;

	return 0;
}