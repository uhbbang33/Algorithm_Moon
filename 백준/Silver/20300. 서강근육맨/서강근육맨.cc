#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	vector<long long> t(n);
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
	}

	sort(t.begin(), t.end());

	long long max = 0;
	if (n % 2 != 0) {
		for (int i = 0; i < n / 2; ++i) {
			long long temp = t[i] + t[n - i - 2];
			if (temp > max)
				max = temp;
		}
		if (max < t[n - 1])
			max = t[n - 1];
	}
	else {
		for (int i = 0; i < n / 2; ++i) {
			long long temp = t[i] + t[n - i - 1];
			if (temp > max)
				max = temp;
		}
	}

	cout << max;

	return 0;
}