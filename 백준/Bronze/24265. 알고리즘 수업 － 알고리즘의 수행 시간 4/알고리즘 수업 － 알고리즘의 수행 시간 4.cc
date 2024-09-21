#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	cin >> n;
	
	n = n * (n - 1) / 2;
	cout << n << "\n" << 2;

	return 0;
}