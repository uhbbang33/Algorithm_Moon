#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int month, date;
	cin >> month >> date;

	if (month < 2 || (month == 2 && date < 18))
		cout << "Before";
	else if (month == 2 && date == 18)
		cout << "Special";
	else
		cout << "After";

	return 0;
}