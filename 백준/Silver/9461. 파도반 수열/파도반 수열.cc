#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	long long arr[101]{ 0, 1, 1, 1, 2, 2 };
	for (int i = 6; i < 101; ++i)
		arr[i] = arr[i - 1] + arr[i - 5];

	int n;
	for (int i = 0; i < t; ++i) {
		cin >> n;
		cout << arr[n] << "\n";
	}

	return 0;
}