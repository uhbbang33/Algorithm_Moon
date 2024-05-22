#include <iostream>
#include <vector>
using namespace std;

int result[50000]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		result[i] = result[i - 1] + 1;
		for (int j = 1; j * j <= i; ++j)
			result[i] = min(result[i], result[i - j * j] +1);
	}

	cout << result[n];

	return 0;
}