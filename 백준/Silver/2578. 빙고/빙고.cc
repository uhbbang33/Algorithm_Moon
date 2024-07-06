#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	map<int, pair<int, int>> bingo;

	int colCnt[5]{};
	int rowCnt[5]{};
	int bingoCnt = 0;
	int plusDiagCnt = 0, minusDiagCnt = 0;

	int num = 0;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> num;
			bingo.insert({ num, make_pair(i, j) });
		}
	}
	
	for (int i = 0; i < 25; ++i) {
		cin >> num;
		int a = bingo[num].first;
		int b = bingo[num].second;
		++rowCnt[a];
		++colCnt[b];

		if (a == b) {
			++minusDiagCnt;
			if (minusDiagCnt == 5) ++bingoCnt;
		}
		if (a + b == 4) {
			++plusDiagCnt;
			if (plusDiagCnt == 5) ++bingoCnt;
		}

		if (rowCnt[a] == 5) ++bingoCnt;
		if (colCnt[b] == 5) ++bingoCnt;

		if (bingoCnt >= 3) {
			cout << i + 1;
			break;
		}
	}

	return 0;
}