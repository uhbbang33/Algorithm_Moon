#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x1, x2, a, b, c, d, e;
	cin >> x1 >> x2 >> a >> b >> c >> d >> e;

	int temp = x2 - x1;

	cout << (x2 * x2 * x2 - x1 * x1 * x1) * a / 3
		+ (x2 * x2 - x1 * x1) * (b - d) / 2
		+ (x2 - x1) * (c - e);

	return 0;
}