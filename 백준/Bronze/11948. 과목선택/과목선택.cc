#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[4]{};
	for (int& i : arr)
		cin >> i;

	int arr2[2]{};
	for (int& i : arr2)
		cin >> i;
	
	sort(arr, arr + 4, greater<>());
	sort(arr2, arr2 + 2, greater<>());

	cout << arr[0] + arr[1] + arr[2] + arr2[0];

	return 0;
}