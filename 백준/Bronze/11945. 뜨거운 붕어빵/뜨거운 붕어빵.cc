#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	char arr[11][11]{};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cin >> arr[i][j];

		for (int j = 0; j < m / 2; ++j)
			swap(arr[i][j], arr[i][m - j - 1]);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << arr[i][j];
		cout << "\n";
	}

	return 0;
}