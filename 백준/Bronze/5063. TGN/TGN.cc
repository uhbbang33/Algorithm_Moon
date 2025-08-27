#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int r, e, c;
		cin >> r >> e >> c;

		int t = e - r;
		if (t > c)
			cout << "advertise\n";
		else if (t < c)
			cout << "do not advertise\n";
		else
			cout << "does not matter\n";
	}

	return 0;
}