#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, j;
	cin >> n >> m >> j;

	int result = 0;
	int left = 1, right = m;
	for (int i = 0; i < j; ++i) {
		int apple = 0;
		cin >> apple;

		int move = 0;
		if (apple < left) {
			move = left - apple;
			left -= move;
			right -= move;
		}
		else if (right < apple) {
			move = apple - right;
			left += move;
			right += move;
		}

		result += move;
	}

	cout << result;

	return 0;
}