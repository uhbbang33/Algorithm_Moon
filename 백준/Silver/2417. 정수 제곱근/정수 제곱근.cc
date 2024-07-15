#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	cin >> n;
	
	long long sqr = sqrt(n);
	if (sqr * sqr < n)
		cout << sqr + 1;
	else
		cout << sqr;

	return 0;
}