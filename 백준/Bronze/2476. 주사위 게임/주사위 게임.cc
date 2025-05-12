#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int result = 0;
	for (int i = 0; i < n; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		
		int score = 0;
		
		if (a == b && b == c)
			score = 10000 + a * 1000;
		else if (a == b || a == c)
			score = 1000 + a * 100;
		else if (b == c)
			score = 1000 + b * 100;
		else
			score = max(a, max(b, c)) * 100;

		result = max(result, score);
	}

	cout << result;

	return 0;
}