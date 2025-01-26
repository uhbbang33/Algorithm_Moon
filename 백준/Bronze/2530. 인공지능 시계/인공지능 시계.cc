#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	a += d / 3600;
	d %= 3600;
	
	b += d / 60;
	d %= 60;

	c += d;

	if (c > 59) {
		c -= 60;
		++b;
	}
	if (b > 59) {
		b -= 60;
		++a;
	}
	while (a > 23) {
		a -= 24;
	}

	cout << a << " " << b << " " << c;


	return 0;
}
