#include <iostream>
using namespace std;

#define MAX_HEIGHT 640000000

int height[250001]{};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, b;
	cin >> n >> m >> b;

	int totalArea = n * m;
	int min = MAX_HEIGHT, max = 0;
	for (int i = 0; i < totalArea; ++i) {
		cin >> height[i];

		if (height[i] > max) max = height[i];
		if (height[i] < min) min = height[i];
	}

	int resultTime = 1e9;
	int resultHeight = 0;

	for (int i = max; i >= min; --i) {
		int currentTime = 0;
		int inventory = b;

		for (int j = 0; j < totalArea; ++j) {
			if (height[j] > i) {
				currentTime += 2 * (height[j] - i);
				inventory += height[j] - i;
			}
			else if (height[j] < i) {
				int buildCnt = i - height[j];

				inventory -= buildCnt;
				currentTime += buildCnt;
			}
		}

		if (inventory >= 0 && resultTime > currentTime) {
			resultTime = currentTime;
			resultHeight = i;
		}
	}

	cout << resultTime << " " << resultHeight;

	return 0;
}