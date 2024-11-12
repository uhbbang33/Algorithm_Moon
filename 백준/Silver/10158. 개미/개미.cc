#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int w, h, p, q, t;
	cin >> w >> h >> p >> q >> t;

	if ((p + t) / w % 2 == 0)
		p = (p + t) % w;
	else
		p = w - (p + t) % w;

	if ((q + t) / h % 2 == 0)
		q = (q + t) % h;
	else
		q = h - (q + t) % h;

	cout << p << " " << q;

	return 0;
}