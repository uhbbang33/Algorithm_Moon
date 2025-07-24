#include <iostream>
#include <queue>
using namespace std;

int board[101]{};
bool visited[101]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n + m; ++i) {
		int start, end;
		cin >> start >> end;

		board[start] = end;
	}

	queue<pair<int, int>> q;
	q.push({ 1, 0 });

	int result = 1000;

	while (!q.empty()) {
		int location = q.front().first;
		int moveCnt = q.front().second;
		q.pop();

		for (int i = 1; i <= 6; ++i) {
			int next = location + i;

			if (board[next] != 0)
				next = board[next];

			if (next > 100 || visited[next])
				continue;
			
			visited[next] = true;
			q.push({ next, moveCnt + 1 });

			if (next == 100)
				result = min(moveCnt + 1, result);
		}
	}

	cout << result;

	return 0;
}