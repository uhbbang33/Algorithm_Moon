#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int aWin = 0, bWin = 0;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;

		if (a > b)
			++aWin;
		else if (a < b)
			++bWin;
	}

	cout << aWin << " " << bWin;

	return 0;
}