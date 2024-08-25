#include <iostream>
using namespace std;

char arr[65][65]{};

void Func(int y, int x, int size) {
	char curNum = arr[y][x];

	for (int i = y; i < size + y; ++i) {
		for (int j = x; j < size + x; ++j) {
			if (arr[i][j] != curNum) {
				cout << "(";
				int s = size / 2;
				Func(y, x, s);
				Func(y, x + s, s);
				Func(y + s, x, s);
				Func(y + s, x + s, s);
				cout << ")";
				return;
			}
		}
	}

	cout << curNum;
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];

	Func(0, 0, n);

	return 0;
}