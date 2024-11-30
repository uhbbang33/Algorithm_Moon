#include <iostream>
using namespace std;

long long Calculate(long long a, long long b, long long c) {
	if (b == 0)
		return 1;

	long long temp = Calculate(a, b / 2, c);

	temp = temp * temp % c;

	if (b % 2 == 0)
		return temp;
	else
		return temp * a % c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long a, b, c;
	cin >> a >> b >> c;
	cout << Calculate(a, b, c);

	return 0;
}