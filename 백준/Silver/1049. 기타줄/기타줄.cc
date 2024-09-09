#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int minPackage = 1000;
	int minOne = 1000;

	for (int i = 0; i < m; ++i) {
		int p, o;
		cin >> p >> o;

		minPackage = min(p, minPackage);
		minOne = min(o, minOne);
	}

	int pNum = n / 6;
	int oNum = n % 6;

	int result = pNum * minPackage + oNum * minOne;
	result = min(result, (pNum + 1) * minPackage);
	result = min(result, minOne * n);

	cout << result;

	return 0;
}