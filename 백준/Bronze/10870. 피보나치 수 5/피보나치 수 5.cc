#include <iostream>
using namespace std;

int fibonacci(int N);

int main()
{
	cout.tie(NULL);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	cin >> N;

	cout << fibonacci(N);

	return 0;
}

int fibonacci(int N)
{
	if (N == 0 || N == 1)
		return N;
	
	return fibonacci(N - 1) + fibonacci(N - 2);
}