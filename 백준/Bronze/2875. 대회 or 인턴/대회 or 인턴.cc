#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	
	int result = 0;
	while (n + m >= k + 3 && n >= 2 && m >= 1) {
		n -= 2;
		m -= 1;

		++result;
	}

	cout << result;

	return 0;
}