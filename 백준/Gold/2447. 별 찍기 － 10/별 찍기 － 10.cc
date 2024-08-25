#include <iostream>
using namespace std;

char arr[2200][2200]{};

void Func(int y, int x, int size) {
	int s = size / 3;
	for (int i = y + s; i < y + s + s; ++i)
		for (int j = x +s; j < x + s + s; ++j)
			arr[i][j] = ' ';

	if (size >= 9) {
		Func(y, x, s);
		Func(y, x + s, s);
		Func(y, x + s + s, s);
		Func(y + s, x, s);
		Func(y + s, x + s + s, s);
		Func(y + s + s, x, s);
		Func(y + s + s, x + s, s);
		Func(y + s + s, x + s + s, s);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			arr[i][j] = '*';

	Func(0, 0, n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << arr[i][j];
		cout << "\n";
	}

	return 0;
}