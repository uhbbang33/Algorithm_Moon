#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

char board[5][5]{};
unordered_set<string> s;

int dy[4]{ 1,-1, 0, 0 };
int dx[4]{ 0, 0, -1,1 };

void MakeStr(int y, int x) {
	queue<pair<string, pair<int, int>>> q;
	q.push({ "" + board[y][x], {y, x} });

	while (!q.empty()) {
		string curStr = q.front().first;
		int curY = q.front().second.first;
		int curX = q.front().second.second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = dy[i] + curY;
			int nx = dx[i] + curX;

			if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
				continue;

			string nextStr = curStr + board[ny][nx];
			if (nextStr.length() == 6)
				s.insert(nextStr);
			else
				q.push({ nextStr, {ny, nx} });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 5; ++i) 
		for (int j = 0; j < 5; ++j) 
			cin >> board[i][j];

	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			MakeStr(i, j);

	cout << s.size();

	return 0;
}