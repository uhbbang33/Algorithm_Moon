#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int result = 0;
	for (int i = 0; i < 5; ++i) {
		int temp;
		cin >> temp;
		result += temp;
	}
	
	cout << result;

	return 0;
}