#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int a, b;
	cin >> a >> b;

	int cnt = 0;
	while (a < b) {
		if (b % 10 == 1)
			b /= 10;
		else if (b % 2 == 0)
			b /= 2;
		else
			break;

		++cnt;
	}

	if (cnt != 0 && a == b)
		cout << cnt + 1;
	else cout << "-1";

	return 0;
}