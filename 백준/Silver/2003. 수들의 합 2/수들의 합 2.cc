#include <iostream>
using namespace std;

int arr[10001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int left = 0, right = 0;
	int result = 0;
	int sum = arr[right];

	while (left <= right && right < n) {
		if (sum >= m) {
			if (sum == m) {
				++result;

				sum += arr[++right];
			}

			if (left == right)
				sum += arr[++right];
			sum -= arr[left++];
		}
		else if (sum < m)
		{
			if (right == n)
				break;

			sum += arr[++right];
		}
	}

	cout << result;

	return 0;
}