#include <iostream>
using namespace std;

int r, c;
char arr[21][21]{};
int maxResult = 1;
bool visited[26]{};

const int dy[4]{ 1,-1,0,0 };
const int dx[4]{ 0,0,-1, 1 };

void DFS(int y, int x, int curResult)
{
	for (int i = 0; i < 4; ++i) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;

		if (ny < 0 || nx < 0 || ny >= r || nx >= c)
			continue;

		int curAlpha = arr[ny][nx] - 'A';

		if (visited[curAlpha]) {
			maxResult = max(curResult, maxResult);
			continue;
		}

		visited[curAlpha] = true;
		DFS(ny, nx, curResult + 1);
		visited[curAlpha] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; ++i) 
		for (int j = 0; j < c; ++j) 
			cin >> arr[i][j];

	visited[arr[0][0] - 'A'] = true;

	DFS(0, 0, 1);

	cout << maxResult;

	return 0;
}