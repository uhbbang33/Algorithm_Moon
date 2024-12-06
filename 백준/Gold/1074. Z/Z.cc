#include <iostream>
using namespace std;

#define Z_MIN_SIZE 4

int n, r, c;
int num = 0;

void Func(int y, int x, int size) {
	if (size > 2) {
		int s = size / 2;

		if (y + s > r && x + s > c) {
			Func(y, x, s);
			return;
		}
		else
			num += s * s;

		if (y + s > r && x + s + s > c) {
			Func(y, x + s, s);
			return;
		}
		else
			num += s * s;

		if (y + s + s > r && x + s > c) {
			Func(y + s, x, s);
			return;
		}
		else
			num += s * s;

		if (x + s + s > c && y + s + s > r)
			Func(y + s, x + s, s);
	}
	else {
		if (y == r && x == c)
			cout << num;
		if (y == r && x + 1 == c)
			cout << num + 1;
		if (y + 1 == r && x == c)
			cout << num + 2;
		if (y + 1 == r && x + 1 == c)
			cout << num + 3;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> r >> c;

	int size = 1;
	for (int i = 0; i < n; ++i)
		size *= 2;

	Func(0, 0, size);

	return 0;
}