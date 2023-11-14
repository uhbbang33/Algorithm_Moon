#include <iostream>
using namespace std;

int factorial(int a) {
	int r = 1;
	for (int i = a; i > 0; --i)
		r *= i;

	return r;
}

int main()
{
	//이항계수: n개의 원소에서 k개의 원소를 뽑아내는 경우의 수 ( nCk )
	int n = 0, k = 0;
	cin >> n >> k;

	cout << factorial(n) / (factorial(k) * factorial(n - k));
	
	return 0;
}