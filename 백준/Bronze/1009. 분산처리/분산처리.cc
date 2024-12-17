#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 0;
	cin >> t;

	while (t--) {
		int a, b;
		cin >> a >> b;

		int temp = 1;
		while (b--) {
			temp *= a;
			temp %= 10;
		}

		if (temp == 0)
			cout << "10\n";
		else
			cout << temp << "\n";
	}

	return 0;
}