#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int p;
	cin >> p;

	while (p--) {
		int t;
		cin >> t;

		int arr[21]{};

		int result = 0;
		for (int i = 0; i < 20; ++i) {
			int student;
			cin >> student;

			arr[i] = student;

			for (int j = i - 1; j >= 0; --j) {
				if (arr[j] > arr[j + 1]) {
					swap(arr[j], arr[j+1]);

					++result;
				}
				else
					break;
			}
		}

		cout << t << " " << result << "\n";
	}

	return 0;
}