#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int cnt[5]{};

	for (int i = 1; i <= n; ++i) {
		int x, y;
		cin >> x >> y;

		if (x == 0 || y == 0)
			++cnt[0];
		else if (x > 0 && y > 0)
			++cnt[1];
		else if (x < 0 && y > 0)
			++cnt[2];
		else if (x < 0 && y < 0)
			++cnt[3];
		else if (x > 0 && y < 0)
			++cnt[4];
	}

	for (int i = 1; i <= 4; ++i)
		cout << "Q" << i << ": " << cnt[i] << "\n";
	cout << "AXIS: " << cnt[0];

	return 0;
}