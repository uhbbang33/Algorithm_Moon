#include <iostream>
using namespace std;

int main()
{
	int year = 0;

	cin >> year;

	if (((year % 4 == 0) && !(year % 100 == 0)) || year % 400 == 0)
	{
		cout << "1" << endl;
	}
	else
		cout << "0" << endl;

	return 0;
}