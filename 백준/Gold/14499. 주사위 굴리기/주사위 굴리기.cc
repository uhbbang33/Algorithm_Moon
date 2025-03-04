#include <iostream>
using namespace std;

enum DIRECTION { NONE, EAST, WEST, NORTH, SOUTH };
enum DICEDIR { TOP, UP, RIGHT, LEFT, DOWN, BOTTOM };

int board[21][21]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, y, x, k;
	cin >> n >> m >> y >> x >> k;

	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j) 
			cin >> board[i][j];

	// top, up, right, left, down, bottom
	int dice[6]{ 0,0,0,0,0,0 };
	int curY = y, curX = x;

	for (int i = 0; i < k; ++i) {
		int move;
		cin >> move;

		int tempDice[6]{};
		for (int i = 0; i < 6; ++i)
			tempDice[i] = dice[i];

		if (move == EAST) {
			tempDice[TOP] = dice[LEFT];
			tempDice[RIGHT] = dice[TOP];
			tempDice[LEFT] = dice[BOTTOM];
			tempDice[BOTTOM] = dice[RIGHT];

			++curX;
		}
		else if (move == WEST) {
			tempDice[TOP] = dice[RIGHT];
			tempDice[RIGHT] = dice[BOTTOM];
			tempDice[LEFT] = dice[TOP];
			tempDice[BOTTOM] = dice[LEFT];

			--curX;
		}
		else if (move == SOUTH) {
			tempDice[TOP] = dice[DOWN];
			tempDice[UP] = dice[TOP];
			tempDice[DOWN] = dice[BOTTOM];
			tempDice[BOTTOM] = dice[UP];

			++curY;
		}
		else if (move == NORTH) {
			tempDice[TOP] = dice[UP];
			tempDice[UP] = dice[BOTTOM];
			tempDice[DOWN] = dice[TOP];
			tempDice[BOTTOM] = dice[DOWN];
			
			--curY;
		}

		if (curY >= n || curX >= m || curY < 0 || curX < 0) {
			curY = y;
			curX = x;
			continue;
		}

		y = curY;
		x = curX;

		swap(tempDice, dice);
		if (board[y][x] == 0) {
			board[y][x] = dice[BOTTOM];
		}
		else {
			dice[BOTTOM] = board[y][x];
			board[y][x] = 0;
		}

		cout << dice[TOP] << "\n";
	}


	return 0;
}
