#include <iostream>
#include <string>
using namespace std;

int arr[100001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	long long s;
	cin >> n >> s;

	int sum = 0;
	int left = 0, right = 0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if (sum < s) {
			sum += arr[i];
			right = i;
		}
	}

	if (sum < s) {
		cout << "0";
		return 0;
	}

	int minLength = right + 1;
	while (right < n) {
		if (s <= sum) {
			minLength = min(minLength, right - left + 1);

			sum -= arr[left];
			++left;
		}
		else if (s > sum) {
			++right;
			sum += arr[right];
		}
	}
	
	cout << minLength;

	return 0;
}