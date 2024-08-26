#include <iostream>
using namespace std;

int arr[100001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;
	
	long long sum = 0;
	long long result = 0;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}

	for (int i = 0; i < n; ++i) {
		sum -= arr[i];
		result += sum * arr[i];
	}

	cout << result;

	return 0;
}