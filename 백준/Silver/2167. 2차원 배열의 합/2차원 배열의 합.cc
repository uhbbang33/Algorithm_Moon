#include <iostream>
using namespace std;

int sum[301][301]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			cin >> sum[i][j];
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}

	int k;
	cin >> k;

	for (int i = 0; i < k; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << sum[c][d]
			- sum[a - 1][d]
			- sum[c][b - 1]
			+ sum[a - 1][b - 1] << "\n";
	}

	return 0;
}