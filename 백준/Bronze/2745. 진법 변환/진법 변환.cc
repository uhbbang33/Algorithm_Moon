#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string n;
	int b;
	cin >> n >> b;

	long long result = 0;
	for (int i = 0; i < n.length(); ++i) {
		long long a = 0;
		if (!isalpha(n[i]))
			a = n[i] - '0';
		else
			a = n[i] - 'A' + 10;

		for (int j = 0; j < n.length() - i - 1; ++j)
			a *= b;
		result += a;
	}

	cout << result;
	return 0;
}