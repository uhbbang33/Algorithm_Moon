#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 5 * n; ++j)
			cout << "@";
		cout << "\n";
	}
	
	for (int i = 0; i < 4 * n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << "@";
		}
		cout << "\n";
	}

	return 0;
}