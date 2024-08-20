#include <iostream>
using namespace std;

#define MAX_N 123456 * 2

bool isPrime[MAX_N + 1]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill_n(isPrime, MAX_N + 1, true);

	isPrime[0] = false;
	isPrime[1] = false;

	for (int i = 2; i * i <= MAX_N; ++i)
		for (int j = i * i; j <= MAX_N; j += i) 
			isPrime[j] = false;

	int n = -1;
	while (1) {
		cin >> n;

		if (n == 0)
			break;

		int cnt = 0;
		for (int i = n + 1; i <= n * 2; ++i)
			if (isPrime[i])
				++cnt;

		cout << cnt << "\n";
	}

	return 0;
}