#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m = -1, f = -1;
	while (1) {
		cin >> m >> f;
		if (m == 0 && f == 0)
			break;

		cout << m + f << "\n";
	}

	return 0;
}
