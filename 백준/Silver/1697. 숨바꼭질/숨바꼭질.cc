#include <iostream>
#include <queue>

using namespace std;

int n, k;
queue<int> q;

int graph[100001];

int bfs() {
	int a = 0;

	while (!q.empty()) {
		a = q.front();
		q.pop();

		int d[3] = { a - 1, a + 1, a * 2 };

		for (int i = 0; i < 3; ++i) {
			if (d[i] < 0 || d[i] > 100000) continue;

			if (graph[d[i]] == 0) {
				graph[d[i]] = graph[a] + 1;
				q.push({ d[i] });
			}

			if (d[i] == k)
				return graph[d[i]];
		}
	}
	return graph[a] - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;

	q.push(n);

	if (n == k)
		cout << 0;
	else
		cout << bfs();

	return 0;
}