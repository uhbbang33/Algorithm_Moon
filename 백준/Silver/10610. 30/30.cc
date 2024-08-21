#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string n;
	cin >> n;

	sort(n.begin(), n.end(), greater<>());

	int sum = 0;
	for (int i = 0; i < n.length(); ++i)
		sum += n[i] - '0';

	if (sum % 3 == 0 && n.back() == '0')
		cout << n;
	else
		cout << "-1";

	return 0;
}