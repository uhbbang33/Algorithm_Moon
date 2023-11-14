#include <iostream>
using namespace std;

int main()
{
	int a = 1, b = 1, c = 1;
	while (1) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			break;
		if (a * a == b * b + c * c) {
			cout << "right" << endl;
			continue;
		}
		if (b * b == a * a + c * c) {
			cout << "right" << endl;
			continue;
		}
		if (c * c == b * b + a * a) {
			cout << "right" << endl;
			continue;
		}
		cout << "wrong" << endl;
		
	}
	return 0;
}