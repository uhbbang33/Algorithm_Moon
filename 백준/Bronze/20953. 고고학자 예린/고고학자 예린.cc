#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int a, b;
		cin >> a >> b;

		int sum = 0;

		for (int j = 0; j < a + b; ++j)
			for (int k = 0; k < j; ++k)
				++sum;

		cout << (a + b) * sum << "\n";
	}

	return 0;
}