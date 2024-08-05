#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int k;
	long long arr[3]{};
	cin >> k;

	for (int i = 0; i < k; ++i) {
		cin >> arr[0] >> arr[1] >> arr[2];
		sort(arr, arr + 3);

		long long result = (arr[0] + arr[1]) * (arr[0] + arr[1]) + arr[2] * arr[2];
		cout << result << "\n";
	}

	return 0;
}