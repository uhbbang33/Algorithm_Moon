#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[9]{};
	int sum = 0;
	for (int i = 0; i < 9; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (i == j) continue;

			if (sum - arr[i] - arr[j] == 100) {
				arr[i] = 0;
				arr[j] = 0;
				break;
			}
		}
		if (arr[i] == 0)
			break;
	}
	
	for (int i = 0; i < 9; ++i) {
		if (arr[i] != 0)
			cout << arr[i] << "\n";
	}

	return 0;
}