#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;

	int aSum = 0;
	int bSum = 0;
	int cur = 1, cnt = 0;

	for (int i = 1; i <= b; ++i) {
		if (i == a)
			aSum = bSum;

		bSum += cur;

		++cnt;
		if (cur == cnt) {
			++cur;
			cnt = 0;
		}
	}

	cout << bSum - aSum;

	return 0;
}
