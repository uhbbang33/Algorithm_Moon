#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		
		if (n % 2 == 0)
			--n;

		int sum = 0;
		while (n > 0) {
			sum += n;
			n -= 2;
		}

		cout << sum << "\n";
	}


	return 0;
}