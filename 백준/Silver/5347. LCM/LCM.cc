#include <iostream>
using namespace std;

long long int GCD(long long int a, long long int b) {
	if (b == 0)
		return a;
	else return GCD(b, a % b);
}

long long int LCM(long long int a, long long int b) {
	return a * b / GCD(a, b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	while (n--) {
		int a, b;
		cin >> a >> b;
		if (a < b)
			swap(a, b);

		cout << LCM(a, b) << "\n";
	}

	return 0;
}