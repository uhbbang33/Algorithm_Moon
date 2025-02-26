#include <iostream>
#include <queue>
using namespace std;

int cnt[17][17]{};
bool isWall[17][17]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> isWall[i][j];

	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ { 1,1 }, { 1, 2 } });

	while (!q.empty()) {
		pair<int, int> head = q.front().first;
		pair<int, int> tail = q.front().second;

		int headY = head.first;
		int headX = head.second;
		int tailY = tail.first;
		int tailX = tail.second;

		q.pop();

		pair<int, int> horizonDiff = { tailY, tailX + 1 };
		pair<int, int> verticalDiff = { tailY + 1, tailX };
		pair<int, int> diagonalDiff = { tailY + 1, tailX + 1 };

		// 가로 or 대각선
		if (headY == tailY || (headX != tailX && headY != tailY)) {
			if (horizonDiff.second <= n && !isWall[horizonDiff.first][horizonDiff.second]) {
				q.push({ tail, horizonDiff });
				++cnt[horizonDiff.first][horizonDiff.second];
			}
		}

		// 세로 or 대각선
		if (headX == tailX || (headX != tailX && headY != tailY)) {
			if (verticalDiff.first <= n && !isWall[verticalDiff.first][verticalDiff.second]) {
				q.push({ tail, verticalDiff });
				++cnt[verticalDiff.first][verticalDiff.second];
			}
		}

		if (diagonalDiff.first <= n && diagonalDiff.second <= n
			&& !isWall[horizonDiff.first][horizonDiff.second]
			&& !isWall[diagonalDiff.first][diagonalDiff.second]
			&& !isWall[verticalDiff.first][verticalDiff.second]) {
			q.push({ tail, diagonalDiff });
			++cnt[diagonalDiff.first][diagonalDiff.second];
		}
	}

	cout << cnt[n][n];

	return 0;
}
