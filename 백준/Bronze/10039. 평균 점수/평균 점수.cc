#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int sum = 0;
	for (int i = 0; i < 5; ++i) {
		int a;
		cin >> a;

		if (a >= 40)
			sum += a;
		else
			sum += 40;
	}

	cout << sum / 5;

	return 0;
}