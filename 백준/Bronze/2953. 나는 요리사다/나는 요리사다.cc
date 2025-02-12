#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	pair<int, int> winner = { 0,0 };

	for (int i = 1; i <= 5; ++i) {
		int sum = 0;
		for (int j = 0; j < 4; ++j) {
			int score;
			cin >> score;

			sum += score;
		}

		if (winner.second < sum) {
			winner.first = i;
			winner.second = sum;
		}
	}

	cout << winner.first << " " << winner.second;

	return 0;
}
