#include <iostream>
using namespace std;

int cost[101][101]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		if (cost[a][b] == 0 || cost[a][b] > c)
			cost[a][b] = c;
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= n; ++k) {
				if (j == k || cost[j][i] == 0 || cost[i][k] == 0)
					continue;

				int temp = cost[j][i] + cost[i][k];
				if (cost[j][k] == 0 || cost[j][k] > temp)
					cost[j][k] = temp;
			}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			cout << cost[i][j] << " ";
		cout << "\n";
	}

	return 0;
}