#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int k;
	cin >> k;

	int prevDir = 0, prevLen = 0;

	int result = 0;
	int height = 0, width = 0;
	bool isRemove = false;
	int first = 0;

	for (int i = 0; i < 6; ++i) {
		int dir, len;
		cin >> dir >> len;

		if (i == 0)
			first = len;

		if (dir == 1)
			width += len;
		else if (dir == 3)
			height += len;

		if ((dir == 3 && prevDir == 1)
			|| (dir == 1 && prevDir == 4)
			|| (dir == 2 && prevDir == 3)
			|| (dir == 4 && prevDir == 2)) {
			result -= prevLen * len;
			isRemove = true;
		}

		if (i == 5 && !isRemove)
			result -= len* first;

		prevDir = dir;
		prevLen = len;
	}

	result += height * width;
	result *= k;
	
	cout << result;
	

	return 0;
}