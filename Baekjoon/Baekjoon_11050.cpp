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
	//���װ��: n���� ���ҿ��� k���� ���Ҹ� �̾Ƴ��� ����� �� ( nCk )
	int n = 0, k = 0;
	cin >> n >> k;

	cout << factorial(n) / (factorial(k) * factorial(n - k));
	
	return 0;
}