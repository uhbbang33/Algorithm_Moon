#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	for (int i = 1; i <= t; ++i) {
		int a, b;
		cin >> a >> b;

		cout << "Case " << i << ": " << a + b << "\n";
	}

	return 0;
}