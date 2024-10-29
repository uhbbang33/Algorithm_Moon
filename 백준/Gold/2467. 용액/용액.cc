#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_SUM 2 * 1e9

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());

	int minAbs = MAX_SUM;
	int resultLeft = 0, resultRight = 0;
	int left = 0, right = n - 1;
	
	while (left < right) {
		int sum = v[left] + v[right];
		int sumAbs = abs(sum);

		if (sumAbs < minAbs) {
			minAbs = sumAbs;
			resultLeft = v[left];
			resultRight = v[right];	
		}

		if (sum < 0)
			++left;
		else
			--right;
	}

	cout << resultLeft << " " << resultRight;

	return 0;
}