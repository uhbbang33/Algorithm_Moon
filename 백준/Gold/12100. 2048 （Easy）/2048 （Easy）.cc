#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<vector<int>> boardVec;

boardVec board;

int n = 0;
int result = 0;

vector<int> Compress(const vector<int>& row) {
	vector<int> newRow(n, 0);

	int idx = 0;
	int prev = 0;

	for (int i = 0; i < n; ++i) {
		if (row[i] == 0)
			continue;

		if (prev == 0)
			prev = row[i];
		else {
			if (prev == row[i]) {
				newRow[idx] = prev * 2;
				result = max(result, newRow[idx]);
				prev = 0;
			}
			else {
				newRow[idx] = prev;
				prev = row[i];
			}
			++idx;
		}
	}

	if (prev != 0)
		newRow[idx] = prev;
	
	return newRow;
}

boardVec Move(const boardVec& v, int dir) {
	boardVec next(n, vector<int>(n, 0));

	if (dir == 0) {	// 왼
		for (int i = 0; i < n; ++i)
			next[i] = Compress(v[i]);
	}
	else if (dir == 1) {	// 오
		for (int i = 0; i < n; ++i) {
			vector<int> row = v[i];

			reverse(row.begin(), row.end());
			row = Compress(row);
			reverse(row.begin(), row.end());

			next[i] = row;
		}
	}
	else if (dir == 2) {	// 위
		for (int i = 0; i < n; ++i) {
			vector<int> col(n);
			for (int j = 0; j < n; ++j)
				col[j] = v[j][i];
			
			col = Compress(col);

			for (int j = 0; j < n; ++j)
				next[j][i] = col[j];
		}
	}
	else if (dir == 3) {	// 아래
		for (int i = 0; i < n; ++i) {
			vector<int> col(n);
			for (int j = 0; j < n; ++j)
				col[j] = v[j][i];

			reverse(col.begin(), col.end());
			col = Compress(col);
			reverse(col.begin(), col.end());

			for (int j = 0; j < n; ++j)
				next[j][i] = col[j];
		}
	}

	return next;
}

void DFS(const boardVec& cur, int depth) {
	if (depth == 5) return;
	
	for (int i = 0; i < 4; ++i) {
		boardVec nextBoard = Move(cur, i);
		DFS(nextBoard, depth + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	board.resize(n);

	for (int i = 0; i < n; ++i) {
		board[i].resize(n);
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
			result = max(result, board[i][j]);
		}
	}
	
	DFS(board, 0);

	cout << result;

	return 0;
}