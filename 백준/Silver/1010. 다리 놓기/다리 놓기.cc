#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n, m, result, temp;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		cin >> n >> m;
		result = 1;
		temp = 1;

		for (int j = m; j > (m - n); --j) {
			result *= j;
			result /= temp;
			++temp;
		}

		cout << result << "\n";
	}

	return 0;
}