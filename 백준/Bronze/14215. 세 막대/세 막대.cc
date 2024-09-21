#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a[3]{ };
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	
	if (a[0] + a[1] <= a[2])
		a[2] = a[0] + a[1] - 1;

	cout << a[0] + a[1] + a[2];

	return 0;
}