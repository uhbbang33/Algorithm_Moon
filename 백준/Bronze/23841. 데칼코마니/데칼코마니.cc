#include <iostream>
using namespace std;

char board[51][51]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;

			if (c != '.') {
				board[i][m - j - 1] = c;
				board[i][j] = c;
			}
			else if (board[i][j] != NULL)
				continue;
			else
				board[i][j] = c;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << board[i][j];
		cout << "\n";
	}

	return 0;
}