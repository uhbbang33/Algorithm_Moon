#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n - i; ++j)
			cout << " ";
		for (int j = 1; j <= i * 2 - 1; ++j) {
			if (j % 2 != 0)
				cout << "*";
			else
				cout << " ";
		}
		cout << "\n";
	}

	return 0;
}