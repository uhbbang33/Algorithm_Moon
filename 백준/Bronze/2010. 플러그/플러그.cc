#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	int result = 0;
	for (int i = 0; i < n; ++i) {
		int multi = 0;
		cin >> multi;

		result += multi - 1;
	}
	
	cout << result + 1;

	return 0;
}