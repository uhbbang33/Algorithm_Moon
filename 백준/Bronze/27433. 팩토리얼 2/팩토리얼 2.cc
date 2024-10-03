#include <iostream>
using namespace std;

long long result = 1;
long long Fac(int x) {
	result *= x;

	if (x > 1)
		return Fac(x - 1);
	else
		return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	if (n == 0) cout << 1;
	else cout << Fac(n);

	return 0;
}