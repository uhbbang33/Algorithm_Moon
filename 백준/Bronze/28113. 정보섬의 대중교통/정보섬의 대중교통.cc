#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, b;
	cin >> n >> a >> b;
	
	if (b > a)
		cout << "Bus";
	else if (b == a)
		cout << "Anything";
	else
		cout << "Subway";

	return 0;
}