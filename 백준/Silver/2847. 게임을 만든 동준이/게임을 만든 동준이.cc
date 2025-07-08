#include <iostream>
using namespace std;

int arr[101]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int next = arr[n - 1];
	int result = 0;

	for (int i = n - 2; i >= 0; --i) {
		if (next > arr[i]) {
			next = arr[i];
			continue;
		}

		result += arr[i] - next + 1;
		next -= 1;
	}

	cout << result;

	return 0;
}