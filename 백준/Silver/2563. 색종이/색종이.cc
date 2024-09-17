#include <iostream>
using namespace std;

bool isBlack[101][101]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;

		for (int j = a; j < a + 10; ++j) {
			for (int k = b; k < b + 10; ++k) {
				isBlack[j][k] = true;
			}
		}
	}

	int result = 0;
	for (int i = 1; i <= 100; ++i) {
		for (int j = 1; j <= 100; ++j) {
			if (isBlack[i][j])
				++result;
		}
	}

	cout << result;

	return 0;
}