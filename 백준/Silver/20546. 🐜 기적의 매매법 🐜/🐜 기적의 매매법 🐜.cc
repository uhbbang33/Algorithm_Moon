#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int money = 0;
	cin >> money;

	int jun = 0, junLeft = money;
	int sung = 0, sungLeft = money;
	int yesterday = 0, today = 0;
	int plusDayCnt = 0, minusDayCnt = 0;

	for (int i = 0; i < 14; ++i) {
		cin >> today;

		while (junLeft >= today) {
			++jun;
			junLeft -= today;
		}

		if (today > yesterday && i != 0) ++plusDayCnt;
		else plusDayCnt = 0;
		if (today < yesterday && i != 0) ++minusDayCnt;
		else minusDayCnt = 0;

		if (plusDayCnt >= 3) {
			sungLeft += sung * today;
			sung = 0;
		}
		if (minusDayCnt >= 3) {
			while (sungLeft >= today) {
				++sung;
				sungLeft -= today;
			}
		}
		yesterday = today;
	}

	junLeft += jun * today;
	sungLeft += sung * today;

	if (junLeft > sungLeft) cout << "BNP";
	else if (junLeft == sungLeft)cout << "SAMESAME";
	else cout << "TIMING";

	return 0;
}