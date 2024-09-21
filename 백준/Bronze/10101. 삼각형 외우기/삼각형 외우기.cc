#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int a, b, c;
	cin >> a >> b >> c;
	if (a + b + c != 180)
		cout << "Error";
	else if (a == c && c == 60)
		cout << "Equilateral";
	else if (a == b || b == c || a == c)
		cout << "Isosceles";
	else
		cout << "Scalene";

	return 0;
}