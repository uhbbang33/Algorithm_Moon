#include <iostream>
using namespace std;

int board[1000][1000]{};

int dy[4]{ 1, 0, -1, 0 };
int dx[4]{ 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, findNum;
	cin >> n >> findNum;
	
	int cur = n * n;
	int dirCnt = 1;
	int lineCnt = n;
	int remainCnt = n;
	int dir = 0;

	int x = 0, y = 0;

	int resultX = 0, resultY = 0;

	while (cur != 0) {
		board[y][x] = cur;
		if (cur == findNum) {
			resultY = y;
			resultX = x;
		}
		--cur;
		--lineCnt;

		if (lineCnt == 0) {
			--dirCnt;
			if (dirCnt == 0) {
				dirCnt = 2;
				--remainCnt;
			}

			lineCnt = remainCnt;

			++dir;
			if (dir == 4)
				dir = 0;
		}

		x += dx[dir];
		y += dy[dir];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << board[i][j] << " ";
		cout << "\n";
	}
	cout << resultY + 1 << " " << resultX + 1;


	return 0;
}