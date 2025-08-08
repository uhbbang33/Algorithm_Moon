#include <iostream>
#include <math.h>
using namespace std;

bool IsPrime(int num) {
	for (int i = 2; i <= sqrt(num); ++i)
		if (num % i == 0)
			return false;
	return true;
}

void DFS(int x, int n) {
	if (n == 1) {
		cout << x << "\n";
		return;
	}

	for (int i = 1; i <= 9; i += 2) {
		int next = x * 10 + i;

		if (IsPrime(next))
			DFS(next, n - 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int startNum[4]{ 2,3,5,7 };

	for (int i = 0; i < 4; ++i)
		DFS(startNum[i], n);

	return 0;
}