#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	float w, h;
	cin >> w >> h;

	cout << fixed;
	cout.precision(1);

	cout << w * h / 2;

	return 0;
}