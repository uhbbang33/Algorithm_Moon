#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;
	
	n /= 4;
	for (int i = 0; i < n; ++i)
		cout << "long ";
	cout << "int";

	return 0;
}