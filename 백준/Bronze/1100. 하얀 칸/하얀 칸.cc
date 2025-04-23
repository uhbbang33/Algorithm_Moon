#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int result = 0;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			char c;
			cin >> c;
			if (c == 'F') {
				if (i % 2 == 0 && j % 2 == 0)
					++result;
				else if (i % 2 == 1 && j % 2 == 1)
					++result;
			}
		}
	}

	cout << result;

	return 0;
}