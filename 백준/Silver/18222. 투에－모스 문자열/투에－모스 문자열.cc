#include <iostream>
using namespace std;

long long func(long long x) {
	if (x == 0 || x == 1) return x;
	else if (x % 2 == 0)
		return func(x / 2);
	else
		return 1 - func(x / 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long k = 0;
	cin >> k;

	--k;
	cout << func(k);

	return 0;
}