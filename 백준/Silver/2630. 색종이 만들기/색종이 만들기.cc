#include <iostream>

using namespace std;

int n = 0;
int arr[129][129]{};
int resultWhite = 0, resultBlack = 0;

void Func(int startX, int startY, int endX, int endY) {
	int startColor = arr[startY][startX];
	bool shouldCut = false;

	for (int i = startY; i <= endY; ++i) {
		for (int j = startX; j <= endX; ++j) {
			if (startColor != arr[i][j]) {
				shouldCut = true;
				break;
			}
		}
		if (shouldCut)
			break;
	}

	if (shouldCut) {
		int halfX = (startX + endX) / 2;
		int halfY = (startY + endY) / 2;

		Func(startX, startY, halfX, halfY);
		Func(halfX + 1, startY, endX, halfY);
		Func(startX, halfY + 1, halfX, endY);
		Func(halfX + 1, halfY + 1, endX, endY);
	}
	else {
		if (startColor == 0) ++resultWhite;
		else ++resultBlack;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];

	Func(0, 0, n - 1, n - 1);

	cout << resultWhite << "\n";
	cout << resultBlack << "\n";

	return 0;
}