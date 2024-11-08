#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while (t--) {
		int n, m;
		cin >> n >> m;

		int a, b;
		for (int i = 0; i < m; ++i) {
			cin >> a >> b;
		}

		cout << n - 1 << "\n";
	}

	return 0;
}