#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int plus = 2;
	int result = 2;
	for (int i = 2; i <= n; ++i) {
		result += plus;

		if (i % 2 == 1)
			++plus;
	}

	cout << result;

	return 0;
}