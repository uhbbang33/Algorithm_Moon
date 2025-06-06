#include <iostream>
#include <algorithm>
using namespace std;

int v[15001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v, v + n);

	int result = 0;
	int left = 0, right = n - 1;
	while (left < right) {
		int sum = v[left] + v[right];

		if (sum == m) {
			++result;
			++left;
			--right;
		}
		else if (sum < m)
			++left;
		else if (sum > m)
			--right;
	}

	cout << result;

	return 0;
}