#include <iostream>
#include <algorithm>
using namespace std;

int a[2001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a, a + n);
	
	int result = 0;

	for (int i = 0; i < n; ++i) {
		int left = 0;
		int right = n - 1;

		while (left < right) {
			if (left == i) {
				++left;
				continue;
			}
			if (right == i) {
				--right;
				continue;
			}
			
			int sum = a[left] + a[right];

			if (a[i] == sum) {
				++result;
				break;
			}
			else if (sum < a[i])
				++left;
			else if (sum > a[i])
				--right;
		}
	}

	cout << result;

	return 0;
}