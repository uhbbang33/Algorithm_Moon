#include <iostream>
using namespace std;

#define MOD 1000000009

long long arr[1000001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	for (int i = 4; i <= 1000000; ++i)
		arr[i] = (arr[i - 1] + arr[i - 2] + arr[i - 3]) % MOD;


	while (t--) {
		int n;
		cin >> n;

		cout << arr[n] % MOD << "\n";
	}

	return 0;
}