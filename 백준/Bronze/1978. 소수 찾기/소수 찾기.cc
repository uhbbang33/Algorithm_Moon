#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int num) {
	for (int i = 2; i <= sqrt(num); ++i)
		if (num % i == 0)
			return false;
	return true;
}

int main()
{
	int n;
	cin >> n;
	int count = 0;

	for (int i = 0; i < n; ++i) {
		int num = 0;
		cin >> num;

		if (num == 1) continue;
		if (isPrime(num))
			++count;
	}
	
	cout << count;

	return 0;
}

