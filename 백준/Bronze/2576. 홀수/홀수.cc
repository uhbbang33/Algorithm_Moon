#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int result = 0;
	int minNum = 1000;
	for (int i = 0; i < 7; ++i) {
		int a;
		cin >> a;

		if (a % 2 != 0) {
			result += a;
			minNum = min(minNum, a);
		}
	}

	if (result == 0)
		cout << "-1";
	else {
		cout << result << "\n";
		cout << minNum;
	}
	return 0;
}
