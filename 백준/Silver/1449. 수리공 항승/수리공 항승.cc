#include <iostream>
#include <algorithm>
using namespace std;

float arr[1001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l;
	cin >> n >> l;
	
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr, arr + n);

	int result = 0;
	for (int i = 0; i < n;) {
		float temp = arr[i];
		while (arr[i] >= temp && arr[i] <= temp + l - 1)
			++i;

		++result;
	}

	cout << result;

	return 0;
}