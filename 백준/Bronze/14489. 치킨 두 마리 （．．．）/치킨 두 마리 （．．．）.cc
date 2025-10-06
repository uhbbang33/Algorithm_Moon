#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	a += b;
	c *= 2;

	if (a < c)
		cout << a;
	else
		cout << a - c;

	return 0;
}