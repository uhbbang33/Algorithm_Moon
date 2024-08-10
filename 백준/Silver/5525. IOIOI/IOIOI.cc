#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0, m = 0;
	cin >> n >> m;

	int checkCnt = 2 * n + 1;
	int curCnt = 0;
	int resultCnt = 0;

	char c;
	for (int i = 0; i < m; ++i) {
		cin >> c;

		if (curCnt % 2 == 0) {
			if (c == 'I')
				++curCnt;
			else if (c == 'O')
				curCnt = 0;
		}
		else if (curCnt % 2 == 1) {
			if (c == 'O')
				++curCnt;
			else if (c == 'I')
				curCnt = 1;
		}
		
		if (checkCnt <= curCnt && curCnt % 2 == 1) {
			++resultCnt;
		}
	}

	cout << resultCnt;

	return 0;
}