#include <iostream>
#include <math.h>
using namespace std;

int dp[100001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; ++i) {
		dp[i] = 100000;

		for (int j = sqrt(i); j > 0; --j) {
			int curCnt = 1;
			int curN = i;

			curN -= j * j;
			curCnt += dp[curN];
			dp[i] = min(curCnt, dp[i]);
		}
	}
	cout << dp[n];

	return 0;
}