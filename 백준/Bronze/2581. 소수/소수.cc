#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int num) {
	for (int i = 2; i <= sqrt(num); ++i)
		if (num % i == 0)
			return false;

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n;
	cin >> m >> n;
	if (m == 1) ++m;

	bool isFirst = true;
	int firstPrime = 0;
	int sum = 0;

	for (int i = m; i <= n; ++i) {
		if (isPrime(i)) {
			if (isFirst) {
				firstPrime = i;
				isFirst = false;
			}
			sum += i;
		}
	}

	if (isFirst)
		cout << "-1";
	else
		cout << sum << "\n" << firstPrime;

	return 0;
}