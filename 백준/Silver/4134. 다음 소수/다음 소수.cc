#include <iostream>
using namespace std;

bool IsPrime(long long a) {
	for (long long i = 2; i * i <= a; ++i)
		if (a % i == 0)
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		long long n;
		cin >> n;
		if (n == 0 || n == 1) {
			cout << 2 << "\n";
			continue;
		}

		for (long long j = n; j < 2 * n; ++j) {
			if (IsPrime(j)) {
				cout << j << "\n";
				break;
			}
		}
	}

	return 0;
}