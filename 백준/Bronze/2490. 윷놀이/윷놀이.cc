#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 3; ++i) {
		int cnt = 0;

		for (int j = 0; j < 4; ++j) {
			int a;
			cin >> a;
			if (a == 0)
				++cnt;
		}

		if (cnt == 1)
			cout << "A" << "\n";
		else if (cnt == 2)
			cout << "B" << "\n";
		else if (cnt == 3)
			cout << "C" << "\n";
		else if (cnt == 4)
			cout << "D" << "\n";
		else
			cout << "E" << "\n";
	}

	return 0;
}