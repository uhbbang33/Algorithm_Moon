#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int result = 0;
	result = n / 5 + n / 25 + n / 125;
	cout << result;

	return 0;
}