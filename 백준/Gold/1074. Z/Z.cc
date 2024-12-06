#include <iostream>
using namespace std;

#define Z_MIN_SIZE 4

int n, r, c;
int num = 0;

void Func(int y, int x, int size) {
	if (size > 2) {
		int s = size / 2;

		for (int i = 0; i < 4; ++i) {
			int ny = y + (i / 2) * s;
			int nx = x + (i % 2) * s;

			if (ny <= r && r < ny + s
				&& nx <= c && c < nx + s) {
				Func(ny, nx, s);
				return;
			}
			else
				num += s * s;
		}
	}
	else {
		if (y == r && x + 1 == c)
			++num;
		if (y + 1 == r) {
			if (x == c)
				num += 2;
			if (x + 1 == c)
				num += 3;
		}

		cout << num;
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