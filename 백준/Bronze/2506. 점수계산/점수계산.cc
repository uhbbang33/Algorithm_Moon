#include <iostream>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int result = 0;
	int plusScore = 0;
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;

		if (a == 1) {
			++plusScore;
			result += plusScore;
		}
		else plusScore = 0;
	}

	cout << result;

	return 0;
}