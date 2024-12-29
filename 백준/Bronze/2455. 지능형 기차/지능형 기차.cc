#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int cur = 0, result = 0;
	for (int i = 0; i < 4; ++i) {
		int a, b;
		cin >> a >> b;

		cur += b;
		cur -= a;
		
		result = max(result, cur);
	}

	cout << result;

	return 0;
}