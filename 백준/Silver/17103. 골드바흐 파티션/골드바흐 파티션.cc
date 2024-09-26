#include <iostream>
using namespace std;

bool prime[1000001]{};

bool IsPrime(int a) {
	for (int i = 2; i * i <= a; ++i)
		if (a % i == 0)
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	for (int i = 2; i < 1000001; ++i)
		prime[i] = IsPrime(i);

	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;

		int cnt = 0;
		for (int j = 2; j <= n / 2; ++j)
			if (prime[j] && prime[n - j])
				++cnt;
		cout << cnt << "\n";
	}

	return 0;
}