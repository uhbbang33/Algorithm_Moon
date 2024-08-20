#include <iostream>
using namespace std;

int GCD(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, a, b;
	cin >> t;

	while (--t >= 0) {
		cin >> a >> b;
		if (a < b) swap(a, b);
		
		int result = a * b / GCD(a, b);
		cout << result << "\n";
	}

	return 0;
}