#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int min = 1000, max = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;

		if (a < min) min = a;
		if (a > max) max = a;
	}

	cout << max - min;

	return 0;
}