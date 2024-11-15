#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	double a[3]{};
	cin >> a[0] >> a[1] >> a[2];
	
	double r1 = (a[0] * a[1]) / a[2];
	double r2 = (a[0] / a[1]) * a[2];

	cout << max((long long)floor(r1),(long long)floor(r2));

	return 0;
}