#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	cin >> x;

	sort(v.begin(), v.end());

	int result = 0;
	int left = 0, right = n-1;
	while (left < right) {
		int sum = v[left] + v[right];

		if (sum == x) {
			++result;
			++left;
			--right;
		}
		else if (sum > x)
			--right;
		else if (sum < x) 
			++left;
	}

	cout << result;

	return 0;
}