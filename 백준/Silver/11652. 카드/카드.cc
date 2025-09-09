#include <iostream>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	map<long long, int> m;
	
	int maxCnt = 0;
	long long result = 0;

	for (int i = 0; i < n; ++i) {
		long long card;
		cin >> card;
		
		++m[card];

		if (maxCnt < m[card]
			|| (maxCnt == m[card] && result > card)) {
			result = card;
			maxCnt = m[card];
		}
	}

	cout << result;

	return 0;
}