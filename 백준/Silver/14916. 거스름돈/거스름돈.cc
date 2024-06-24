#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;
	
	int min = n;
	for (int i = n/5; i > 0; --i) {
		int tempResult = 0;
		int tempN = n;
		
		tempResult += i;
		tempN -= i * 5;

		tempResult += tempN / 2;
		tempN %= 2;

		if (tempN != 0)
			continue;

		if (min > tempResult)
			min = tempResult;
	}

	if (min == n) {
		if (n % 2 == 0)
			min = n / 2;
		else
			min = -1;
	}

	cout << min;

	return 0;
}