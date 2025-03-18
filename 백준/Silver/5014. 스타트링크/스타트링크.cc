#include <iostream>
#include <queue>
using namespace std;

int visitCnt[1000001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int highest, s, target, u, d;
	cin >> highest >> s >> target >> u >> d;

	if (s == target) {
		cout << "0";
		return 0;
	}

	// 층, 움직인 횟수
	queue<pair<int, int>> q;
	q.push({ s, 0 });

	int result = 0;

	while (!q.empty()) {
		int floor = q.front().first;
		int cnt = q.front().second;

		if (floor == target) {
			result = cnt;
			break;
		}

		q.pop();

		int upFloor = floor + u;
		if (upFloor <= highest && (!visitCnt[upFloor] || visitCnt[upFloor] > cnt + 1)) {
			q.push({ upFloor, cnt + 1 });
			visitCnt[upFloor] = cnt + 1;
		}

		int downFloor = floor - d;
		if (downFloor > 0 && (!visitCnt[downFloor] || visitCnt[downFloor] > cnt + 1)) {
			q.push({ downFloor, cnt + 1 });
			visitCnt[downFloor] = cnt + 1;
		}
	}

	if (result == 0)
		cout << "use the stairs";
	else
		cout << result;

	return 0;
}