#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string n;
	cin >> n;

	int arr[10]{};
	for (int i = 0; i < n.length(); ++i)
		arr[i] = n[i] - '0';

	sort(arr, arr + n.length(), greater<>());

	for (int i = 0; i < n.length(); ++i)
		cout << arr[i];

	return 0;
}