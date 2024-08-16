#include <iostream>
#include <math.h>
#include <vector>
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

	vector<int> v;
	int sum = 0;
	for (int i = m; i <= n; ++i) {
		if (isPrime(i)) {
			v.push_back(i);
			sum += i;
		}
	}

	if (v.empty())
		cout << "-1";
	else
		cout << sum << "\n" << v[0];

	return 0;
}