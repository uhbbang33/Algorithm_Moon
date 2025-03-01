#include <iostream>
#include <math.h>
using namespace std;

#define MOD 1000000007

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int h, x;
	cin >> h >> x;

	long long sum = 0;
	long long cur = 1;

	for (int i = 1; i <= h; ++i) {
		long long snowCnt;
		cin >> snowCnt;
		
		cur = (cur * x) % MOD;
		sum = (sum + (cur * snowCnt) % MOD) % MOD;
	}

	cout << sum;

	return 0;
}
