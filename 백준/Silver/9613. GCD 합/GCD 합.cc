#include <iostream>

using namespace std;

int arr[101]{};

int GCD(int a, int b) {
	if (b == 0)
		return a;
	return GCD(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; ++i)
			cin >> arr[i];

		long long sum = 0;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				sum += GCD(arr[i], arr[j]);

		cout << sum << "\n";
	}

	return 0;
}