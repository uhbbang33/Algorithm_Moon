#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	 
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		float multi = 0;
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			float c, g;
			cin >> c >> g;

			multi += c* g;
			sum += c;
		}
		
		multi /= sum;
		multi = round(multi * 10) / 10;

		cout << fixed;
		cout.precision(1);
		cout << sum << " " << multi << "\n";
	}

	return 0;
}