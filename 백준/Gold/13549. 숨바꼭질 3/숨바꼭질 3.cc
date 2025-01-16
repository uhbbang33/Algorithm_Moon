#include <iostream>
#include <queue>
using namespace std;

int n, k;
bool visited[100001]{};

int Func() {
	queue<pair<int, int>> q;	// location, cnt
	q.push({ n, 0 });
	visited[n] = true;
	
	while (!q.empty()) {
		int curLocation = q.front().first;
		int curTime = q.front().second;
		q.pop();

		if (curLocation == k)
			return curTime;

		int nextMoveArr[3] = { curLocation * 2, curLocation -1, curLocation + 1};

		for (int i = 0; i < 3; ++i) {
			int nextMove = nextMoveArr[i];

			if (nextMove > 100000 || nextMove < 0
				|| visited[nextMove])
				continue;

			if (i == 0)
				q.push({ nextMove, curTime });
			else
				q.push({ nextMove, curTime + 1 });

			visited[nextMove] = true;
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	cout << Func();

	return 0;
}