#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	int code1[41]{};
	code1[3] = 2;
	code1[4] = 3;
	for (int i = 5; i <= n; ++i)
		code1[i] = code1[i - 2] + code1[i - 1];

	cout << code1[n] << " " << n - 2;
	

	return 0;
}