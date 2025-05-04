#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	int arr[9]{};
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr, arr + n);

	int result = 0;
	while (next_permutation(arr, arr + n)) {
		int temp = 0;
		for (int i = 0; i < n - 1; ++i)
			temp += abs(arr[i] - arr[i + 1]);
		result = max(temp, result);
	}

	cout << result;

	return 0;
}