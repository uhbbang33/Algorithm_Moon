#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> house(n);
	for (int i = 0; i < n; ++i)
		cin >> house[i];

	sort(house.begin(), house.end());

	if (n % 2 == 1)
		cout << house[n / 2];
	else
		cout << house[n / 2 - 1];

	return 0;
}