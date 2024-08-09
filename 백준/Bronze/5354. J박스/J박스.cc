#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 0;
	cin >> t;

	int boxSize = 0;
	for (int i = 0; i < t; ++i) {
		cin >> boxSize;

		for (int j = 0; j < boxSize; ++j) {
			for (int k = 0; k < boxSize; ++k) {
				if (j == 0 || j == boxSize - 1)
					cout << "#";
				else if (k == 0 || k == boxSize - 1)
					cout << "#";
				else
					cout << "J";
			}
			cout << "\n";
		}
		cout << "\n";
	}


	return 0;
}