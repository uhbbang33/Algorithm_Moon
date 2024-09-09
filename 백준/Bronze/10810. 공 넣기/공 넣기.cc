#include <iostream>
using namespace std;

int arr[101]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	while (m--) {
		int i, j, k;
		cin >> i >> j >> k;

		for (int l = i; l <= j; ++l)
			arr[l] = k;
	}
	
	for (int i = 1; i <= n; ++i)
		cout << arr[i] << " ";

	return 0;
}