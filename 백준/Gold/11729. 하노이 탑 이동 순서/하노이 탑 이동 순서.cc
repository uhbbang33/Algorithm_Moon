#include <iostream>
#include <math.h>
using namespace std;

void Hanoi(int n, int from, int by, int to) {
	if (n == 1) {
		cout << from << " " << to << "\n";
		return;
	}
	Hanoi(n - 1, from, to, by);
	cout << from << " " << to << "\n";
	Hanoi(n - 1, by, from, to);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	int result = pow(2, n) - 1;
	cout << result << "\n";

	Hanoi(n, 1, 2, 3);

	return 0;
}