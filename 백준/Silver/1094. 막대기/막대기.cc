#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x;
	cin >> x;

	int result = 0;

	for (int i = 6; i >= 0; --i) {
		int temp = pow(2, i);
		if (x >= temp) {
			x -= temp;
			++result;
		}
		if (x == 0)
			break;
	}

	cout << result;

	return 0;
}