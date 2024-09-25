#include <iostream>
using namespace std;

int GCD(int a, int b) {
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long a, b;
	cin >> a >> b;
	
	cout << a * b / GCD(max(a, b), min(a, b));

	return 0;
}