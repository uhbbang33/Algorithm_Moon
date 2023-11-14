#include <iostream>
using namespace std;

int GCD(int a, int b) {
	if (b == 0)
		return a;
	return GCD(b, a % b);
}

int main()
{
	int num1, num2;
	cin >> num1 >> num2;

	int result = GCD(num1, num2);
	int result2 = num1 * num2 / result;

	cout << result << endl << result2;

	return 0;
}