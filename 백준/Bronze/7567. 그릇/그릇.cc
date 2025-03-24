#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	char cur = '.';
	string str;
	cin >> str;

	int sum = 0;
	for (auto s : str) {
		if (s != cur)
			sum += 10;
		else
			sum += 5;

		cur = s;
	}

	cout << sum;

	return 0;
}