#include <iostream>

using namespace std;

char board[101][101]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];

	int result = 0;
	for (int i = 0; i < n; ++i) {
		int empty = 0;

		for (int j = 0; j < n; ++j) {
			if (board[i][j] == '.')
				++empty;
			else
				empty = 0;

			if (empty == 2)
				++result;
		}

	}
	cout << result << " ";
	result = 0;

	for (int i = 0; i < n; ++i) {
		int empty = 0;

		for (int j = 0; j < n; ++j) {
			if (board[j][i] == '.')
				++empty;
			else
				empty = 0;

			if (empty == 2)
				++result;
		}
	}
	cout << result;

	return 0;
}