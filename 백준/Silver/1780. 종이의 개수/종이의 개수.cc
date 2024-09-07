#include <iostream>
using namespace std;

int arr[2200][2200]{};
int result[3]{};

void DAC(int startX, int startY, int endX, int endY) {
	int cur = arr[startY][startX];

	for (int i = startY; i <= endY; ++i) {
		for (int j = startX; j <= endX; ++j) {
			if (arr[i][j] != cur) {
				int tempX = (endX - startX + 1) / 3;
				int tempY = (endY - startY + 1) / 3;

				DAC(startX, startY, startX + tempX - 1, startY + tempY - 1);
				DAC(startX + tempX, startY, endX - tempX, startY + tempY - 1);
				DAC(endX - tempX + 1, startY, endX, startY + tempY - 1);
				
				DAC(startX, startY + tempY, startX + tempX - 1, endY - tempY);
				DAC(startX + tempX, startY + tempY, endX - tempX, endY - tempY);
				DAC(endX - tempX + 1, startY + tempY, endX, endY - tempY);
				
				DAC(startX, endY - tempY + 1, startX + tempX - 1, endY);
				DAC(startX + tempX, endY - tempY + 1, endX - tempX, endY);
				DAC(endX - tempX + 1, endY - tempY + 1, endX, endY);

				return;
			}
		}
	}

	if (cur == -1)
		++result[0];
	else if (cur == 0)
		++result[1];
	else if(cur == 1)
		++result[2];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> arr[i][j];

	DAC(1, 1, n, n);

	cout << result[0] << "\n";
	cout << result[1] << "\n";
	cout << result[2] << "\n";

	return 0;
}