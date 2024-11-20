#include <iostream>
using namespace std;

int n;
int visited[16][16]{};
int result = 0;

void NQueen(int y) {
	if (y == n) {
		++result;
		return;
	}

	for (int x = 0; x < n; ++x) {
		bool isPossible = true;

		// 어차피 row 까지만 퀸을 놓았으므로 i는 row까지
		for (int i = 0; i < y; ++i) {
			if (visited[i][x]
				|| (x - (y - i) >= 0 && visited[i][x - (y - i)])
				|| (x + (y - i) < n && visited[i][x + (y - i)]))
				isPossible = false;

			if (!isPossible)
				break;
		}

		if (isPossible) {
			visited[y][x] = true;
			NQueen(y + 1);
			visited[y][x] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	NQueen(0);
	
	cout << result;

	return 0;
}