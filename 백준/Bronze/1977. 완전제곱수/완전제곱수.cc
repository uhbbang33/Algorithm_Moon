#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n;
	cin >> m >> n;

	int minNum = 10001;
	int sum = 0;

	for (int i = m; i <= n; ++i) {
		int temp = sqrt(i);

		if (i == temp * temp) {
			sum += i;
			minNum = min(minNum, i);
		}
	}

	if (sum != 0)
		cout << sum << "\n" << minNum;
	else
		cout << "-1";
    
	return 0;
}