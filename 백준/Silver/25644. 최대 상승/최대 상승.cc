#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int minA = 1000000001, maxA = 0;
	int result = 0;
	while (n--) {
		int a;
		cin >> a;

		if (a < minA) {
			minA = a;
			maxA = 0;
		}
		if (a > maxA) {
			maxA = a;

			result = max(result, maxA - minA);
		}
	}

	cout << result;

	return 0;
}