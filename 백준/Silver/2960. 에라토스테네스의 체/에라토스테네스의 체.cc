#include <iostream>

using namespace std;

bool prime[1001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	int cnt = 0;
	for (int i = 2; i <= n; ++i) {
		for (int j = i; j <= n; j += i) {
			if (prime[j]) continue;
			prime[j] = true;

			++cnt;
			if (cnt == k) {
				cout << j;
				return 0;
			}
		}
	}

	return 0;
}