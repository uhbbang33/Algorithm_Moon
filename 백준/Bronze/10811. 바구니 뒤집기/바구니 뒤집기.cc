#include <iostream>
using namespace std;

int arr[101]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		arr[i] = i;

	while (m--) {
		int i, j;
		cin >> i >> j;

		while (i < j) {
			swap(arr[i], arr[j]);
			++i;
			--j;
		}
	}

	for (int i = 1; i <= n; ++i)
		cout << arr[i] << " ";


	return 0;
}