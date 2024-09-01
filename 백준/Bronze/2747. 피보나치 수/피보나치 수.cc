#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	int f[46]{};
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i <= n; ++i)
		f[i] = f[i - 1] + f[i - 2];
	cout << f[n];

	return 0;
}