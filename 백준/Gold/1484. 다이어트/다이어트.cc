#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long g;
	cin >> g;
	long long curWeight = 0;
	bool dontFat = true;
	for (long long i = 1; i < g; ++i) {
		 curWeight = g + i * i;
		 long long temp = sqrt(curWeight);
		 if (temp * temp == curWeight) {
			 cout << temp << "\n";
			 dontFat = false;
		 }
	}
	if (dontFat) cout << "-1";

	return 0;
}