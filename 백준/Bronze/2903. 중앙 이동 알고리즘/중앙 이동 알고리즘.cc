#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;
	
	int result = 3;
	for (int i = 1; i < n; ++i)
		result += result - 1;

	cout << result * result;

	return 0;
}