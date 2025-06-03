#include <iostream>
using namespace std;

long long arr[1001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	long long sum = 0;
	
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;

		sum += a;
		++arr[sum % m];
	}

	long long result = 0;
	for (int i = 0; i <= m; ++i)
		result += arr[i] * (arr[i] - 1) / 2;

	cout << result + arr[0];

	return 0;
}