#include <iostream>
using namespace std;

int main()
{
	int N = 0;
	cin >> N;
	
	int *divisor = new int[N];
	int max = 0;
	int min = 2147483647;

	for (int i = 0; i < N; ++i) {
		cin >> divisor[i];
		if (max < divisor[i])
			max = divisor[i];
		if (min > divisor[i])
			min = divisor[i];
	}
	cout << max * min;
	delete[] divisor;

	return 0;
}
//https://www.acmicpc.net/problem/1037