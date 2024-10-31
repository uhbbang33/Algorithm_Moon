#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int dp1 = 1, dp2 = 2;
	for (int i = 3; i <= n; ++i) {
		int temp = dp1 + dp2;
		temp %= 15746;
		
		dp1 = dp2;
		dp2 = temp;
	}

	if (n == 1)
		cout << 1;
	else
		cout << dp2;

	return 0;
}