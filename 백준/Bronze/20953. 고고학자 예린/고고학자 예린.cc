#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		long long a, b;
		cin >> a >> b;

		cout << (a + b) * (a + b) * (a + b - 1) / 2<< "\n";
	}

	return 0;
}