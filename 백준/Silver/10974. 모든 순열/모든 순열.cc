#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	int arr[8]{};
	for (int i = 0; i < 8; ++i)
		arr[i] = i + 1;

	do {
		for (int i = 0; i < n; ++i)
			cout << arr[i] << " ";
		cout << "\n";
	} while (next_permutation(arr, arr + n));

	return 0;
}