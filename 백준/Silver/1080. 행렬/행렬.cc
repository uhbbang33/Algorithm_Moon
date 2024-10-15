#include <iostream>
using namespace std;

char arrA[51][51]{};
char arrB[51][51]{};

void Change(int startY, int startX) {
	for (int i = startY; i < startY + 3; ++i)
		for (int j = startX; j < startX + 3; ++j) {
			if (arrA[i][j] == '0')
				arrA[i][j] = '1';
			else
				arrA[i][j] = '0';
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> arrA[i][j];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> arrB[i][j];

	int cnt = 0;
	for (int i = 0; i < n - 2; ++i)
		for (int j = 0; j < m - 2; ++j) {
			if (arrA[i][j] != arrB[i][j]) {
				Change(i, j);
				++cnt;
			}
		}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (arrA[i][j] != arrB[i][j]) {
				cout << "-1";
				return 0;
			}

	cout << cnt;

	return 0;
}