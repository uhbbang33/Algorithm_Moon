#include <iostream>
#include <vector>
using namespace std;

int board[9][9]{};
vector<pair<int, int>> zeroVec;
bool complete = false;

bool Check(int y, int x, int num) {
	for (int i = 0; i < 9; ++i) 
		if (board[y][i] == num || board[i][x] == num)
			return false;

	int yArea = y / 3 * 3;
	int xArea = x / 3 * 3;

	for (int i = yArea; i < yArea + 3; ++i) 
		for (int j = xArea; j < xArea + 3; ++j) 
			if (board[i][j] == num)
				return false;

	return true;
}

void Sudoku(int cnt) {
	if (cnt == zeroVec.size()) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j)
				cout << board[i][j] << " ";
			cout << "\n";
		}
		complete = true;
		return;
	}
	for (int i = 1; i <= 9; ++i) {
		if (Check(zeroVec[cnt].first, zeroVec[cnt].second, i)) {
			board[zeroVec[cnt].first][zeroVec[cnt].second] = i;
			Sudoku(cnt + 1);
		}
		if (complete)
			return;
	}
	board[zeroVec[cnt].first][zeroVec[cnt].second] = 0;

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j) {
			cin >> board[i][j];

			if (board[i][j] == 0)
				zeroVec.push_back({ i, j });
		}

	Sudoku(0);
	
	return 0;
}
