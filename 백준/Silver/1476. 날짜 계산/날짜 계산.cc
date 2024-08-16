#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int e, s, m;
	cin >> e >> s >> m;

	long long curNum = e;
	while (1) {
		if ((curNum % 28 == s || (curNum % 28 == 0 && s == 28))
			&& (curNum % 19 == m || (curNum % 19 == 0 && m == 19))) {
			cout << curNum;
			break;
		}
		curNum += 15;
	}

	return 0;
}