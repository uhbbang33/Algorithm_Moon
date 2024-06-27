#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;
	
	vector<double> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	double result = v[0] / 2 + v[n - 1];
	for (int i = 2; i < n; ++i) {
		if (result < v[n - i])
			result = result / 2 + v[n - i];
		else
			result += v[n - i] / 2;
	}
	cout << result;

	return 0;
}