#include <iostream>
#include <algorithm>
using namespace std;

// https://www.acmicpc.net/problem/10816
int arr[500002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	int card = 0;
	for (int i = 0; i < n; ++i) {
		cin >> card;
		arr[i] = card;
	}
	sort(arr, arr + n);

	int m = 0;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> card;
		cout << upper_bound(arr, arr + n, card) - lower_bound(arr, arr + n, card) << " ";
	}

	return 0;
}