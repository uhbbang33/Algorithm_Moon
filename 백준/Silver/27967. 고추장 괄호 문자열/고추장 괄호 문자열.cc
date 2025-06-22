#include <iostream>
using namespace std;

char arr[21]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int openCnt = 0;
	int gCnt = 0;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];

		if (arr[i] == '(')
			++openCnt;
		else if (arr[i] == ')') {
			--openCnt;

			if (openCnt < 0) {
				for (int j =0; j < i; ++j) {
					if (arr[j] == 'G') {
						arr[j] = '(';
						++openCnt;
						--gCnt;
						break;
					}
				}
			}
		}
		else
			++gCnt;
	}

	for (int i = n - 1; i >= 0 && openCnt > 0; --i) {
		if (arr[i] == 'G') {
			arr[i] = ')';
			--openCnt;
			--gCnt;
		}
	}

	int openNeed = gCnt / 2;

	for (int i = 0; i < n; ++i) {
		if (arr[i] == 'G') {
			if (openNeed > 0) {
				arr[i] = '(';
				--openNeed;
			}
			else
				arr[i] = ')';
		}
		cout << arr[i];
	}

	return 0;
}