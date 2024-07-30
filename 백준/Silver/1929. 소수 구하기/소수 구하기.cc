#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n;
	cin >> m >> n;

	bool result = false;

	for (int i = m; i <= n; ++i) {
		if (i == 1)
			continue;

		result = false;
		for (int j = 2; j * j <= i; ++j) {
			if (i % j == 0) {
				result = true;
				break;
			}
		}
		if (!result)
			cout << i << "\n";
	}

	return 0;
}