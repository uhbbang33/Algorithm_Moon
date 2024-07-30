#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n;
	cin >> m >> n;

	if (m == 1)
		++m;

	bool result = false;

	for (int i = m; i <= n; ++i) {
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