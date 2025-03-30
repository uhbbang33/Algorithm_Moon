#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	float a, b;
	cin >> a >> b;
	
	if (b != 0)
		a -= a / 100 * b;
	
	if (a >= 100)
		cout << 0;
	else cout << 1;

	return 0;
}