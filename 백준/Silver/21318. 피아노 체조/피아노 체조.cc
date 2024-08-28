#include <iostream>
using namespace std;

int level[100001]{};
int mistakeSum[100001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	int mistake = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> level[i];
		
		mistakeSum[i] = mistakeSum[i - 1];
		if (level[i - 1] > level[i])
			++mistakeSum[i];
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int x, y;
		cin >> x >> y;

		cout << mistakeSum[y] - mistakeSum[x] << "\n";
	}

	return 0;
}