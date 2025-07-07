#include <iostream>
#include <queue>
using namespace std;

#define POSSIBLE_DISTANCE 1000

int n, rockX, rockY;
int conX[101]{};
int conY[101]{};

bool BFS() {
	bool visited[101]{};
	queue<int> q;
	q.push(0);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (abs(rockX - conX[cur]) + abs(rockY - conY[cur]) <= POSSIBLE_DISTANCE)
			return true;

		for (int i = 0; i <= n; ++i) {
			if (visited[i] || cur == i)
				continue;

			if (abs(conX[i] - conX[cur]) + abs(conY[i] - conY[cur]) <= POSSIBLE_DISTANCE) {
				q.push(i);
				visited[i] = true;
			}
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	
	while (t--) {
		cin >> n;

		for (int i = 0; i <= n; ++i)
			cin >> conX[i] >> conY[i];

		cin >> rockX >> rockY;

		if (BFS()) cout << "happy\n";
		else cout << "sad\n";
	}

	return 0;
}