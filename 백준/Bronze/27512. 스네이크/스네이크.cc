#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int result = n * m;
	if (result % 2 == 0)
		cout << result;
	else
		cout << result - 1;


	return 0;
}
