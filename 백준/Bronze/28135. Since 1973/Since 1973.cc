#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	int result = 0;
	for (int i = 0; i < n; ++i) {
		int temp = i;
		++result;

		while (temp > 0) {
			if (temp % 100 == 50) {
				++result;
				break;
			}
			else
				temp /= 10;
		}
	}
	cout << result;

	return 0;
}