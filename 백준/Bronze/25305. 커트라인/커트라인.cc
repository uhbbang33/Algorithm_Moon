#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr, arr + n, greater<>());
	cout << arr[k - 1];

	return 0;
}