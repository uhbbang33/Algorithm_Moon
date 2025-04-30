#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	int arr[11]{};

	for (int i = 1; i <= n; ++i) {
		int h;
		cin >> h;

		for (int j = 0; j < n; ++j) {
			if (h == 0 && arr[j] == 0) {
				arr[j] = i;
				break;
			}

			if (arr[j] == 0)
				--h;
		}
	}

	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";

	return 0;
}