#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int i = 1;
	while (n > i) {
		n -= i;
		++i;
	}

	if (i % 2 == 0)
		cout << n << "/" << i - (n - 1);
	else
		cout << i - (n - 1) << "/" << n;

	return 0;
}