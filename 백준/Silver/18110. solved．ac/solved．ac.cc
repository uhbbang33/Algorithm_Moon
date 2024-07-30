#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int diff[300001]{};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;
	if (n == 0) {
		cout << "0";
		return 0;
	}

	for (int i = 0; i < n; ++i)
		cin >> diff[i];
	sort(diff, diff + n);

	double removeNum = n * 0.3 * 0.5;
	removeNum = round(removeNum);

	long double result = 0;
	int cnt = 0;
	for (int i = removeNum; i < n - removeNum; ++i) {
		result += diff[i];
		++cnt;
	}

	result = result / cnt;
	cout << round(result);

	return 0;
}