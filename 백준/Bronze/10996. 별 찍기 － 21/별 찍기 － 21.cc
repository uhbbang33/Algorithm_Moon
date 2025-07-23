#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	if (n == 1) {
		cout << "*";
		return 0;
	}
	
	for (int i = 1; i <= 2 * n; ++i) {
		int t = 0;
		if (n % 2 == 1)
			t = n / 2 + 1;
		else
			t = n / 2;


		if (i % 2 == 1) 
			for (int j = 0; j < t; ++j)
				cout << "* ";
		else 
			for (int j = 0; j < n/2; ++j)
				cout << " *";
		cout << "\n";
	}


	return 0;
}