#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, i;
	cin >> a >> i;

	cout << a * i - a + 1;

	return 0;
}