#include <iostream>
using namespace std;

bool board[101][101]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x1, y1, x2, y2;
	for (int i = 0; i < 4; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = y1; i < y2; ++i)
			for (int j = x1; j < x2; ++j)
				board[i][j] = true;
	}

	int result = 0;
	for (int i = 0; i < 101; ++i) {
		for (int j = 0; j < 101; ++j)
			if (board[i][j])
				++result;
	}
	
	cout << result;


	return 0;
}