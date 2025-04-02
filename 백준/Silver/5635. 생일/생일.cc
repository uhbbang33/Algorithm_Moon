#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string minStr = "", maxStr = "";
	int minD= 100, minM = 100, minY = 3000;
	int maxD = 0, maxM = 0, maxY = 0;

	for (int i = 0; i < n; ++i) {
		string name;
		int d, m, y;

		cin >> name >> d >> m >> y;

		if (minY > y
			|| (minY == y && minM > m)
			|| (minY == y && minM == m && minD > d)) {
			minStr = name;
			minD = d;
			minM = m;
			minY = y;
		}

		if (maxY < y
			|| (maxY == y && maxM < m)
			|| (maxY == y && maxM == m && maxD < d)) {
			maxStr = name;
			maxD = d;
			maxM = m;
			maxY = y;
		}
	}

	cout << maxStr << "\n" << minStr;

	return 0;
}