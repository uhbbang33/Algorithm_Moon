#include <iostream>

using namespace std;

int main() {
	int n, k;	// n: 동전의 종류, k: 가치의 합
	cin >> n >> k;
	
	int* coin = new int [n];
	for (int i = 0; i < n; ++i)
		cin >> coin[i];

	int count = 0;
	for (int i = n-1; i >= 0; --i) {
		count += (k / coin[i]);
		k %= coin[i];
	}
	cout << count;

	return 0;
}