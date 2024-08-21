#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> primeVec;

	for (int i = 2; i < 10001; ++i) {
		bool isPrime = true;

		for (int j = 2; j * j <= i; ++j)
			if (i % j == 0) {
				isPrime = false;
				break;
			}

		if (isPrime)
			primeVec.push_back(i);
	}

	int t;
	cin >> t;

	int n;
	for (int i = 0; i < t; ++i) {
		cin >> n;

		int cnt = 0;
		int first = 0, second = 0;
		while (primeVec[cnt] <= n / 2) {
			int temp = n - primeVec[cnt];
			if (find(primeVec.begin(), primeVec.end(), temp) != primeVec.end()) {
				first = primeVec[cnt];
				second = temp;
			}
			++cnt;
		}

		cout << first << " " << second << "\n";
	}

	return 0;
}