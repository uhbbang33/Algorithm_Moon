#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string board;
	cin >> board;

	string result = "";

	int cnt = 0;
	for (int i = 0; i < board.size(); ++i) {
		if (board[i] == 'X')
			++cnt;
		else if (cnt == 2) {
			result += "BB";
			cnt = 0;
		}

		if (cnt == 4) {
			result += "AAAA";
			cnt = 0;
		}
		if (board[i] == '.') {
			result += ".";
			if (cnt != 0)
				break;
		}
	}

	if (cnt == 2)
		result += "BB";
	else if(cnt != 0)
		result = "-1";

	cout << result;

	return 0;
}