#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001]{};
int dp[10001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	if (n == 1) {
		cout << arr[0];
		return 0;
	}

	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
	dp[2] = max(dp[2], dp[1]);
	for (int i = 3; i <= n; ++i) {
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i],
			dp[i - 2] + arr[i]);

		dp[i] = max(dp[i - 1], dp[i]);
	}

	cout << max(dp[n - 1], dp[n - 2]);

	return 0;
}