#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int temp = n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j)
			cout << " ";
		for (int j = i; j < n; ++j)
			cout << "*";
		cout << "\n";
	}

	return 0;
}