#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int k, n, m;
	cin >> k >> n >> m;

	int result = (k * n) - m;
	if (result > 0)
		cout << result;
	else
		cout << "0";
	
	return 0;
}