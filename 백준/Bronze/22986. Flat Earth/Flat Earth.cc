#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	 
	long long t;
	cin >> t;

	while (t--) {
		long long n, k;
		cin >> n >> k;
		if (n < k)
			k = n;
		cout << (k + 1) * (2 * n - k) * 2 << "\n";
	}

	return 0;
}