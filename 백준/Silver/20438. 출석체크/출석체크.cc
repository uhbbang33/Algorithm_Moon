#include <iostream>
#include <vector>
using namespace std;

int sum[5003]{};
bool sleep[5003]{};
bool accept[5003]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, q, m;
	cin >> n >> k >> q >> m;

	for (int i = 0; i < k; ++i) {
		int sleepNum = 0;
		cin >> sleepNum;
		sleep[sleepNum] = true;
	}

	for (int i = 0; i < q; ++i) {
		int acceptNum = 0;
		cin >> acceptNum;

		if (sleep[acceptNum])
			continue;
		accept[acceptNum] = true;

		int temp = acceptNum;
		while (acceptNum + temp <= n + 2) {
			acceptNum += temp;
			accept[acceptNum] = true;
		}
	}

	for (int i = 3; i <= n + 2; ++i) {
		if (!accept[i] || sleep[i])
			sum[i] = sum[i - 1] + 1;
		else
			sum[i] = sum[i - 1];
	}
	
	for (int i = 0; i < m; ++i) {
		int s, e;
		cin >> s >> e;

		cout << sum[e] - sum[s-1] << "\n";
	}

	return 0;
}