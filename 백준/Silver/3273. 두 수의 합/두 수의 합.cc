#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	cin >> x;

	sort(arr, arr + n);

	int result = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] >= x)
			break;
		for (int j = i + 1; j < n; ++j) {
			if (arr[i] + arr[j] > x)
				break;

			if (arr[i] + arr[j] == x) {
				++result;
				break;
			}
		}
	}

	cout << result;

	return 0;
}