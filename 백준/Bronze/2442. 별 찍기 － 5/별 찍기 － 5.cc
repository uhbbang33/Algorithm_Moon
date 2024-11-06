#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	// 5 4~6 3~7 2~8 1~9

	int left = n-1, right = n-1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < n - i; ++j)
			cout << " ";
		
		for (int j = 0; j < 2* i-1; ++j)
			cout << "*";

		if (i != n)
			cout << " \n";
	}

	return 0;
}