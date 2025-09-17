#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int v, e;
		cin >> v >> e;

		cout << 2 - v + e << "\n";
	}

	return 0;
}