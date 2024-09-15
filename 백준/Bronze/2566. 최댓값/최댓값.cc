#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int maxNum = 0;
	int row = 1, col = 1;
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			int a;
			cin >> a;

			if (a > maxNum) {
				maxNum = a;
				row = i+ 1;
				col = j+ 1;
			}
		}
	}

	cout << maxNum << "\n";
	cout << row << " " << col;	

	return 0;
}