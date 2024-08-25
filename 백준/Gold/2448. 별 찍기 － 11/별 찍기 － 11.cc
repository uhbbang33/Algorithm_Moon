#include <iostream>
using namespace std;

#define MAXNUM 3100 //3072

int n = 0;
char arr[MAXNUM][MAXNUM * 2]{};

void Func(int len, int y, int x) {
	if (len == 3) {
		arr[y][x] = '*';
		arr[y + 1][x - 1] = '*';
		arr[y + 1][x + 1] = '*';
		for (int i = 0; i < 5; ++i)
			arr[y + 2][x - 2 + i] = '*';

		return;
	}

	int temp = len / 2;
	Func(temp, y, x);
	Func(temp, y + temp, x - temp);
	Func(temp, y + temp, x + temp);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n * 2 -1; ++j) 
			arr[i][j] = ' ';

	Func(n, 0, n-1);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n * 2-1; ++j)
			cout << arr[i][j];
		cout << "\n";
	}

	return 0;
}