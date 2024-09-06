#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	cin >> num;

	bool isPlus = true;

	int x = 1, y = 1;
	for (int i = 1; i < num; ++i) {
		if (x == 1 && isPlus) {
			++y;
			isPlus = false;
		}
		else if (y == 1 && !isPlus) {
			++x;
			isPlus = true;
		}
		else if (isPlus) {
			--x;
			++y;
		}
		else if (!isPlus) {
			++x;
			--y;
		}
	}

	cout << x << "/" << y;

	return 0;
}