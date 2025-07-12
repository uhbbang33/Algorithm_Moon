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
		bool possible = true;

		for (int j = 0; j < n - 1; ++j) {
			if (possible 
				&& board[i][j] == '.' 
				&& board[i][j + 1] == '.') {
				++result;
				possible = false;
			}
			if (board[i][j] == 'X')
				possible = true;
		}


	}
	cout << result << " ";
	result = 0;

	for (int i = 0; i < n; ++i) {
		bool possible = true;

		for (int j = 0; j < n - 1; ++j) {
			if (possible
				&& board[j][i] == '.'
				&& board[j + 1][i] == '.') {
				++result;
				possible = false;
			}

			if (board[j][i] == 'X')
				possible = true;
		}
	}
	cout << result;

	return 0;
}