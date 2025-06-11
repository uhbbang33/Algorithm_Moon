#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	int start = 1, end = 2;
	int sum = start + end;
	int result = 1;

	while (start != n) {
		if (sum < n) {
			++end;
			sum += end;
		}
		else if (sum > n) {
			sum -= start;
			++start;
		}
		else if (sum == n) {
			++result;
			++end;
			sum += end;
		}
	}

	cout << result;

	return 0;
}