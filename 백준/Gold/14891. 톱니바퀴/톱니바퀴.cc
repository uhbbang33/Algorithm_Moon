#include <iostream>
#include <deque>
using namespace std;

#define RIGHT_CONTACT 2
#define LEFT_CONTACT 6

deque<char> d[4];

void Rotate(int gearNum, int dir) {
	if (dir == 1) {
		d[gearNum].push_front(d[gearNum].back());
		d[gearNum].pop_back();
	}

	if (dir == -1) {
		d[gearNum].push_back(d[gearNum].front());
		d[gearNum].pop_front();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 8; ++j) {
			char c;
			cin >> c;
			d[i].push_back(c);
		}

	int k;
	cin >> k;

	for (int i = 0; i < k; ++i) {
		int num, dir;
		cin >> num >> dir;
		--num;

		int rotateDir[4]{};
		rotateDir[num] = dir;

		for (int j = num; j < 3; ++j) {
			if (d[j][RIGHT_CONTACT] != d[j + 1][LEFT_CONTACT])
				rotateDir[j + 1] = -rotateDir[j];
			else break;
		}

		for (int j = num; j > 0; --j) {
			if (d[j][LEFT_CONTACT] != d[j - 1][RIGHT_CONTACT])
				rotateDir[j - 1] = -rotateDir[j];
			else break;
		}

		for (int j = 0; j < 4; ++j)
			if (rotateDir[j] != 0)
				Rotate(j, rotateDir[j]);
	}

	int result = 0;
	if (d[0].front() == '1') result += 1;
	if (d[1].front() == '1') result += 2;
	if (d[2].front() == '1') result += 4;
	if (d[3].front() == '1') result += 8;

	cout << result;

	return 0;
}