#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	long long M = 1234567891;
	int L = 0;
	cin >> L;

	string str;
	cin >> str;

	long long result = 0;

	for (int i = 0; i < str.length(); ++i) {
		long long hash = str[i] - 96;
		
		for (int j = 0; j < i; ++j) {
			hash *= 31;
			hash %= M;
		}

		result += hash;
		result %= M;
	}
	cout << result << endl;

	return 0;
}
