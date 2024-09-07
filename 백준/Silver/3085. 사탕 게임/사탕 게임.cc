#include <iostream>
using namespace std;

char arr[51][51]{};
int n;

int CheckLength(int r, int c) {
	int curLength = 0;
	int maxLength = 0;
	char cur = '1';

	// row
	for (int i = 0; i < n; ++i) {
		if (cur != arr[r][i]) {
			maxLength = max(maxLength, curLength);
			curLength = 1;
			cur = arr[r][i];
		}
		else
			++curLength;
	}
	maxLength = max(maxLength, curLength);

	// col
	curLength = 0;
	cur = '1';

	for (int i = 0; i < n; ++i) {
		if (cur != arr[i][c]) {
			maxLength = max(maxLength, curLength);
			curLength = 1;
			cur = arr[i][c];
		}
		else
			++curLength;
	}
	maxLength = max(maxLength, curLength);

	return maxLength;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) 
			cin >> arr[i][j];

	int maxLength = 0;

	// 바꾸지 않은 경우도 먼저 체크
	for (int i = 0; i < n; ++i)
		maxLength = max(CheckLength(i, i), maxLength);

	// 오른쪽, 아래만 바꾸기
	// 해당 열, 행만 체크
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (j + 1 < n && arr[i][j] != arr[i][j + 1]) {
				swap(arr[i][j], arr[i][j + 1]);
				maxLength = max(CheckLength(i, j), maxLength);
				maxLength = max(CheckLength(i, j + 1), maxLength);
				swap(arr[i][j], arr[i][j + 1]);
			}
			if (i + 1 < n && arr[i][j] != arr[i + 1][j]) {
				swap(arr[i][j], arr[i+1][j]);
				maxLength = max(CheckLength(i, j), maxLength);
				maxLength = max(CheckLength(i + 1, j), maxLength);
				swap(arr[i][j], arr[i + 1][j]);
			}
		}
	}

	cout << maxLength;

	return 0;
}