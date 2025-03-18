#include <iostream>
#include <queue>
using namespace std;

bool visited[1000001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int highest, s, target, u, d;
	cin >> highest >> s >> target >> u >> d;

	// 층, 움직인 횟수
	queue<pair<int, int>> q;
	q.push({ s, 0 });
	visited[s] = true;

	int result = -1;

	while (!q.empty()) {
		int floor = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (floor == target) {
			result = cnt;
			break;
		}

		int upFloor = floor + u;
		if (upFloor <= highest && !visited[upFloor]) {
			q.push({ upFloor, cnt + 1 });
			visited[upFloor] = true;
		}

		int downFloor = floor - d;
		if (downFloor > 0 && !visited[downFloor]) {
			q.push({ downFloor, cnt + 1 });
			visited[downFloor] = true;
		}
	}

	if (result == -1)
		cout << "use the stairs";
	else
		cout << result;

	return 0;
}