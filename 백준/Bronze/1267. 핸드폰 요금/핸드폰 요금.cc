#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int y = 0, m = 0;

	for (int i = 0; i < n; ++i) {
		int s;
		cin >> s;

		y += (s / 30 + 1) * 10;
		m += (s / 60 + 1) * 15;
	}

	if (y < m) cout << "Y " << y;
	else if (m < y) cout << "M " << m;
	else cout << "Y M " << y;
	
	return 0;
}