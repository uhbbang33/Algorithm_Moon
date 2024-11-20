#include <iostream>
using namespace std;

int n;
int result = 0;
int queens[16]{};

void NQueen(int y) {
	if (y == n) {
		++result;
		return;
	}

	for (int x = 0; x < n; ++x) {
		queens[y] = x;
		
		bool isPossible = true;
		for (int i = 0; i < y; ++i) {
			if (queens[i] == queens[y]
				|| abs(queens[y] - queens[i]) == y - i) {
				isPossible = false;
				break;
			}
		}

		if (isPossible)
			NQueen(y + 1);
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