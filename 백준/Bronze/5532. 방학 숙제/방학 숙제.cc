#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;

	while (1) {
		--l;
		a -= c;
		b -= d;

		if (a <= 0 && b <= 0)
			break;
	}

	cout << l;

	return 0;
}