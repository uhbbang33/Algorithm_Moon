#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, b;
	cin >> n >> b;

	string result;
	while (n > 0) {
		int temp = n % b;
		n /= b;

		char c;
		if (temp >= 10)
			c = temp - 10 + 'A';
		else
			c = temp + '0';

		result += c;
	}
	
	for (int i = result.length() - 1; i >= 0; --i)
		cout << result[i];

	return 0;
}