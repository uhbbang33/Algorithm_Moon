#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int a, b, c;
	cin >> a >> b >> c;

	cout << (b / a) * 3 * c;
	
	return 0;
}