#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	double n;
	cin >> n;

	cout << fixed;
	cout.precision(6);

	cout << n * n * M_PI << "\n";
	cout << n * n * 2;

	return 0;
}