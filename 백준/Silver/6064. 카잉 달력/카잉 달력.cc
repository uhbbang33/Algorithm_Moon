#include <iostream>
using namespace std;

int GCD(int a, int b) {
	while (b != 0) {
		int r = b;
		b = a % b;
		a = r;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, m, n, x, y;
	cin >> t;

	while (--t >= 0) {
		cin >> m >> n >> x >> y;

		int maxYear = (m > n) ? GCD(m, n) : GCD(n, m);
		maxYear = m * n / maxYear;

		int yearCnt = x;
		int tempY = x;
		while (yearCnt <= maxYear) {
			while (tempY > n)
				tempY -= n;

			if (tempY == y) {
				cout << yearCnt << "\n";
				break;
			}

			yearCnt += m;
			tempY += m;
		}
		
		if (yearCnt > maxYear)
			cout << "-1" << "\n";
	}
	
	return 0;
}