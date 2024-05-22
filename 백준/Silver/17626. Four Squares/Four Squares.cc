#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	vector<int> result;
	result.push_back(0);

	for (int i = 1; i <= n; ++i) {
		result.push_back(result[i - 1] + 1);
		for (int j = 1; j * j <= i; ++j)
			result[i] = min(result[i], result[i - j * j] +1);
	}

	cout << result[n];

	return 0;
}