#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, k;
	cin >> n >> k;

	long long left = 1, right = n * n;

	while (left <= right) {
		long long mid = (left + right) / 2;

		long long sum = 0;
		for (int i = 1; i <= n; ++i)
			sum += min(mid / i, n);

		if (sum >= k)
			right = mid - 1;
		else
			left = mid + 1;
	}

	cout << left;

	return 0;
}