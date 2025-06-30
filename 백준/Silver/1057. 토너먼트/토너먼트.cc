#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, kim, im;
	cin >> n >> kim >> im;

	int round = 1;

	while (kim >= 1 && im >= 1) {
		if (kim % 2 == 0)
			kim /= 2;
		else
			kim = kim / 2 + 1;

		if (im % 2 == 0)
			im /= 2;
		else
			im = im / 2 + 1;

		if (kim == im)
			break;

		++round;
	}

	cout << round;

	return 0;
}