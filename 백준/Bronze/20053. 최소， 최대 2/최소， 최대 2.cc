#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 0;
	cin >> t;
	
	int n = 0;
	for (int i = 0; i < t; ++i) {
		cin >> n;

		int max = -1000000;
		int min = 1000000;
		int num = 0;
		for (int j = 0; j < n; ++j) {
			cin >> num;
			if (num < min) min = num;
			if (num > max) max = num;
		}
		cout << min << " " << max << "\n";
	}

	return 0;
}