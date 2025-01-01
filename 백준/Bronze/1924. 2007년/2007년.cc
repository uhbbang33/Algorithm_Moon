#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x, y;
	cin >> x >> y;

	int date = y;
	for (int i = 0; i < x; ++i) {
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			date += 31;
		else if (i == 4 || i == 6 || i == 9 || i == 11)
			date += 30;
		else if (i == 2)
			date += 28;
	}

	date %= 7;
	
	if (date == 1) cout << "MON";
	else if (date == 2)cout << "TUE";
	else if (date == 3)cout << "WED";
	else if (date == 4)cout << "THU";
	else if (date == 5)cout << "FRI";
	else if (date == 6)cout << "SAT";
	else cout << "SUN";

	return 0;
}