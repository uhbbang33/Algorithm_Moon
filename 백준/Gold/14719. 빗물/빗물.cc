#include <iostream>

using namespace std;

#define MAX_HW 501

int block[MAX_HW]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int h, w;
	cin >> h >> w;

	for (int i = 0; i < w; ++i)
		cin >> block[i];

	int result = 0;

	for (int i = 0; i < w; ++i) {
		int leftMax = 0, rightMax = 0;

		for (int j = i - 1; j >= 0; --j)
			leftMax = max(block[j], leftMax);
		for (int j = i + 1; j < w; ++j)
			rightMax = max(block[j], rightMax);

		int m = min(leftMax, rightMax);
		if (m > block[i])
			result += m - block[i];
	}

	cout << result;

	return 0;
}