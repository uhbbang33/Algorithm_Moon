#include <iostream>
#include <deque>
using namespace std;

enum DIR { RIGHT, DOWN, LEFT, UP };

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = { 1, 0, -1, 0 };

int n;
int curDir = RIGHT;
int cntResult = 0;
bool isEndGame = false;
bool isApple[101][101]{};
bool isSnake[101][101]{};

deque<pair<int, int>> d;

bool Func() {
	++cntResult;

	int ny = dy[curDir] + d.front().first;
	int nx = dx[curDir] + d.front().second;

	if (ny <= 0 || ny > n || nx <= 0 || nx > n || isSnake[ny][nx])
		isEndGame = true;

	if (!isApple[ny][nx]) {
		isSnake[d.back().first][d.back().second] = false;
		d.pop_back();
	}

	isSnake[ny][nx] = true;
	isApple[ny][nx] = false;

	d.push_front({ ny, nx });

	return isEndGame;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int k;
	cin >> n >> k;

	for (int i = 0; i < k; ++i) {
		int y, x;
		cin >> y >> x;

		isApple[y][x] = true;
	}

	d.push_front({ 1, 1 });
	isSnake[1][1] = true;

	int l;
	cin >> l;

	for (int i = 0; i < l; ++i) {
		int x;
		char c;
		cin >> x >> c;

		if (isEndGame)
			continue;
		
		const int curCnt = cntResult;
		for (int j = 0; j < x - curCnt; ++j)
			if (Func())
				break;

		if (c == 'L') {
			--curDir;
			if (curDir < 0) curDir = UP;
		}
		else if (c == 'D') {
			++curDir;
			if (curDir > 3) curDir = RIGHT;
		}
	}

	while (!isEndGame)
		Func();

	cout << cntResult;

	return 0;
}