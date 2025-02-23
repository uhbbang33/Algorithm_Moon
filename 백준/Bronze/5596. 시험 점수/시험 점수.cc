#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	int sum[2]{};

	for (int j = 0; j < 2; ++j) {
		for (int i = 0; i < 4; ++i) {
			cin >> n;
			sum[j] += n;
		}
	}

	cout << max(sum[0], sum[1]);

	return 0;
}
