#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int changyoung = 100, sangduck = 100;
	while (n--) {
		int a, b;
		cin >> a >> b;

		if (a > b) 
			sangduck -= a;
		else if (a < b)
			changyoung -= b;
	}

	cout << changyoung << "\n" << sangduck;

	return 0;
}