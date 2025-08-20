#include <iostream>
using namespace std;

int board[1001][1001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, b;
	cin >> n >> a >> b;

	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= n; ++j) 
			cin >> board[i][j];

	int jinseo = board[a][b];

	for (int i = 0; i < n; ++i) {
		if (jinseo < board[i][b] || jinseo < board[a][i]) {
			cout << "ANGRY";
			return 0;
		}
	}

	cout << "HAPPY";

	return 0;
}