#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int resultPlus = 0, resultMinus = 0;
	long long tempResult = 1e10;
	int left = 0, right = n-1;

	while (arr[left] < arr[right]) {
		long long sum = arr[left] + arr[right];

		long long temp = abs(sum);
		if (temp < tempResult) {
			tempResult = temp;
			resultPlus = arr[right];
			resultMinus = arr[left];
		}

		if (sum < 0) ++left;
		else --right;
	}

	cout << resultMinus << " " << resultPlus;

	return 0;
}