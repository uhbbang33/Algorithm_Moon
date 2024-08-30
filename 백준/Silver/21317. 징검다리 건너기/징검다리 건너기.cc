#include <iostream>
using namespace std;

#define MAX 100001

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	pair<int, int> p[21]{};
	int sum[21][2]{};
	int n, k;

	cin >> n;
	for (int i = 1; i < n; ++i)
		cin >> p[i].first >> p[i].second;
	cin >> k;
	
	for (int i = 0; i <= n; ++i) {
		sum[i][0] = MAX;	// 메가 점프 쓰지 않은 상태
		sum[i][1] = MAX;	// 메가 점프 쓴 상태
	}

	sum[1][0] = 0;
	sum[2][0] = p[1].first;
	sum[3][0] = min(p[1].first + p[2].first, p[1].second);

	for (int i = 4; i <= n; ++i) {
		sum[i][0] = min(sum[i - 1][0] + p[i - 1].first,
			sum[i - 2][0] + p[i - 2].second);

		sum[i][1] = min(k + sum[i - 3][0],
			min(sum[i - 1][1] + p[i - 1].first,
				sum[i - 2][1] + p[i - 2].second));
	}

	cout << min(sum[n][0], sum[n][1]);

	return 0;
}