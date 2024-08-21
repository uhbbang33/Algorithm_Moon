#include <iostream>
#include <vector>
using namespace std;

#define MAX 10001

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> primeVec(MAX, true);
	primeVec[0] = false;
	primeVec[1] = false;

	for (int i = 2; i * i < MAX; ++i) {
		if (!primeVec[i]) continue;

		for (int j = i * i; j < MAX; j += i)
			primeVec[j] = false;
	}

	int t;
	cin >> t;

	int n;
	for (int i = 0; i < t; ++i) {
		cin >> n;

		for (int j = n / 2; j >= 2; --j)
			if (primeVec[j] && primeVec[n - j]) {
				cout << j << " " << n - j << "\n";
				break;
			}
	}

	return 0;
}