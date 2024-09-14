#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int half = m / 2;
	int result = 0;

	for (int i = 0; i < n; ++i) {
		int tempResult = 0;
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;

			if (c == 'O')
				++tempResult;
		}
		if (tempResult > half)
			++result;
	}

	cout << result;

	return 0;
}