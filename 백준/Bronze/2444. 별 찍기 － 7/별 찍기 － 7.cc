#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	int maxStar = 2 * n - 1;

	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= maxStar; ++j) {
			if (n - i <= j && j <= n + i)
				cout << "*";
			else if(j < n-i)
				cout << " ";
		}
		cout << "\n";
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j <= maxStar; ++j) {
			if (i < j && j < 2 * n - i)
				cout << "*";
			else if (j < 2 * n - i)
				cout << " ";
		}
		cout << "\n";
	}
	return 0;
}