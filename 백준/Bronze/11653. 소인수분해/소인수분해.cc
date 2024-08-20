#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	if (n == 1)
		return 0;

	int tempN = n;
	for (int i = 2; i * i <= tempN; ++i) {
		while (n % i == 0) {
			n /= i;
			cout << i << "\n";
		}
	}
	if (n != 1)
		cout << n;

	return 0;
}