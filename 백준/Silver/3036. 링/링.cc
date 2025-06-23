#include <iostream>
using namespace std;

int GCD(int a, int b) {
	if (b == 0)
		return a;
	else
		return GCD(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int firstRing;
	cin >> firstRing;
	for (int i = 0; i < n - 1; ++i) {
		int ring;
		cin >> ring;

		int gcd = GCD(firstRing, ring);
		
		cout << firstRing / gcd << "/" << ring / gcd << "\n";
	}

	return 0;
}