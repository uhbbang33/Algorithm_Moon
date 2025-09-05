#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int y, m;
	cin >> y >> m;
	
	cout << m - y + m;

	return 0;
}