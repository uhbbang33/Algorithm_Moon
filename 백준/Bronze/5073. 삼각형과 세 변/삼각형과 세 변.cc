#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a[3]{};

	while (1) {
		cin >> a[0] >> a[1] >> a[2];
		if (a[0] == 0 && a[1] == 0 && a[2] == 0)
			break;
		sort(a, a + 2);

		if (a[2] >= a[1] + a[0])
			cout << "Invalid";
		else if (a[0] == a[1] && a[1] == a[2])
			cout << "Equilateral";
		else if (a[0] == a[1] || a[1] == a[2] || a[0] == a[2])
			cout << "Isosceles";
		else
			cout << "Scalene";
		cout << "\n";
	}
	return 0;
}