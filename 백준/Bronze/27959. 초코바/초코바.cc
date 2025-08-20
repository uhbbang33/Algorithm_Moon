#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	n *= 100;

	if (n >= m)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}