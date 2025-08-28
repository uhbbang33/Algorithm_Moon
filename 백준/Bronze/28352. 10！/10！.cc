#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	long long a = 1;
	for (int i = 2; i <= n; ++i)
		a *= i;
	
	int hour = 7 * 24 * 60 * 60;
	
	cout << a / hour;
	

	return 0;
}