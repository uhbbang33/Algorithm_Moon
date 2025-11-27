#include <iostream>
#include <vector>
using namespace std;

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int result = 64;
int n, m;
char board[9][9]{};

vector<pair<int,int>> cctv;

void MakeSharp(int y, int x, int dir) {
	dir %= 4;

	while (true) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m || board[ny][nx] == '6')
			break;
		if (board[ny][nx] == '0')
			board[ny][nx] = '#';

		y = ny;
		x = nx;
	}
}

void DFS(int idx) {
	if (idx == cctv.size()) {
		int cnt = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (board[i][j] == '0')
					++cnt;

		result = min(cnt, result);
		return;
	}

	char temp[9][9];
	int y = cctv[idx].first;
	int x = cctv[idx].second;

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < n; ++j) 
			for (int k = 0; k < m; ++k) 
				temp[j][k] = board[j][k];

		if (board[y][x] == '1')
			MakeSharp(y, x, i);
		else if (board[y][x] == '2') {
			MakeSharp(y, x, i);
			MakeSharp(y, x, i + 2);
		}
		else if (board[y][x] == '3') {
			MakeSharp(y, x, i);
			MakeSharp(y, x, i + 1);
		}
		else if (board[y][x] == '4') {
			MakeSharp(y, x, i);
			MakeSharp(y, x, i + 1);
			MakeSharp(y, x, i + 2);
		}
		else if (board[y][x] == '5') {
			MakeSharp(y, x, i);
			MakeSharp(y, x, i + 1);
			MakeSharp(y, x, i + 2);
			MakeSharp(y, x, i + 3);
		}

		DFS(idx + 1);

		for (int j = 0; j < n; ++j)
			for (int k = 0; k < m; ++k)
				board[j][k] = temp[j][k];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
			if (board[i][j] != '0' && board[i][j] != '6')
				cctv.push_back({ i,j });
		}
	}

	DFS(0);

	cout << result;

	return 0;
}