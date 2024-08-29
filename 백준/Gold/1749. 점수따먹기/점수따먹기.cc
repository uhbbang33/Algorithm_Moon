#include <iostream>
using namespace std;

int arr[201][201]{};
int sum[201][201]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> arr[i][j];
			sum[i][j] = arr[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}

	int result = arr[1][1];
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j) 
			for (int k = 1; k <= i; ++k) 
				for (int l = 1; l <= j; ++l) {
					int temp = sum[i][j] - sum[k - 1][j] - sum[i][l - 1] + sum[k - 1][l - 1];
					if (temp > result)
						result = temp;
				}

	cout << result;

	return 0;
}