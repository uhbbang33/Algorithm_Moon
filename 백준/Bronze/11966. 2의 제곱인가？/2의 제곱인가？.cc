#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	bool isSquare = true;
	while (n > 1) {
		if (n % 2 != 0) {
			isSquare = false;
			break;
		}
		else
			n /= 2;
	}

	if (isSquare) cout << 1;
	else cout << 0;

	return 0;
}