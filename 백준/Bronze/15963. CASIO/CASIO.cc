#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, m;
	cin >> n >> m;

	if (n == m)
		cout << "1";
	else
		cout << "0";


	return 0;
}