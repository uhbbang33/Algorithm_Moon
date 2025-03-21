#include <iostream>
#include <queue>
using namespace std;

int n, m;
char board[11][11]{};
bool visited[11][11][11][11]{};

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct Ball {
	int moveCnt = 0;
	int redY = 0, redX = 0, blueY = 0, blueX = 0;
};

void Move(int dir, int& y, int& x, int &cnt) {
	while (board[y + dy[dir]][x + dx[dir]] != '#' && board[y][x] != 'O')
	{
		y += dy[dir];
		x += dx[dir];
		++cnt;
	}
}

int BFS(Ball start) {
	queue<Ball> q;
	q.push({ start });

	visited[start.redY][start.redX][start.blueY][start.blueX] = true;

	while (!q.empty()) {
		int moveCnt = q.front().moveCnt;
		
		if (moveCnt >= 10)
			return -1;

		for (int i = 0; i < 4; ++i) {
			int redCnt = 0, blueCnt = 0;
			int redY = q.front().redY;
			int redX = q.front().redX;
			int blueY = q.front().blueY;
			int blueX = q.front().blueX;

			Move(i, redY, redX, redCnt);
			Move(i, blueY, blueX, blueCnt);

			if (board[blueY][blueX] == 'O')
				continue;

			if (board[redY][redX] == 'O') 
				return moveCnt + 1;

			if (redY == blueY && redX == blueX) {
				if (redCnt > blueCnt) {
					redY -= dy[i];
					redX -= dx[i];
				}
				else {
					blueY -= dy[i];
					blueX -= dx[i];
				}
			}

			if (visited[redY][redX][blueY][blueX])
				continue;
			visited[redY][redX][blueY][blueX] = true;

			q.push({ moveCnt + 1, redY, redX, blueY, blueX });
		}

		q.pop();
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	Ball startBall;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 'R') {
				startBall.redY = i;
				startBall.redX = j;
			}
			if (board[i][j] == 'B') {
				startBall.blueY = i;
				startBall.blueX = j;
			}
		}

	cout << BFS(startBall);

	return 0;
}