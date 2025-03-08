#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int total;
	cin >> total;

	for (int i = 0; i < 9; ++i) {
		int cost;
		cin >> cost;
		total -= cost;
	}

	cout << total;

	return 0;
}