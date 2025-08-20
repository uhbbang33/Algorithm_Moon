#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int h, i, a, r, c;
	cin >> h >> i >> a >> r >> c;

	cout << h * i - a * r * c;

	return 0;
}