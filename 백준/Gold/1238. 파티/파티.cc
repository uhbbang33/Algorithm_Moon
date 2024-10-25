#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9

int n, m, x;	// 학생, 도로, 목적지
vector<pair<int, int>> graph[2][1001]{};
int d[2][10001]{};
int result[1001]{};

void Dijkstra(int num) {
	d[num][x] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, x });

	while (!pq.empty()) {
		int distance = pq.top().first;
		int cur = pq.top().second;

		pq.pop();

		if (distance > d[num][cur])
			continue;

		for (int i = 0; i < graph[num][cur].size(); ++i) {
			int nextDistance = distance + graph[num][cur][i].second;
			int next = graph[num][cur][i].first;

			if (d[num][next] > nextDistance) {
				d[num][next] = nextDistance;
				pq.push({nextDistance, next});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> x;

	for (int i = 0; i < m; ++i) {
		int start, end, t;
		cin >> start >> end >> t;

		graph[0][start].push_back({ end, t });
		graph[1][end].push_back({ start, t });
	}

	for (int j = 0; j <= n; ++j) {
		d[0][j] = INF;
		d[1][j] = INF;
	}
	
	Dijkstra(0);
	Dijkstra(1);

	int maxResult = 0;
	for (int i = 1; i <= n; ++i)
		maxResult = max(maxResult, d[0][i] + d[1][i]);

	cout << maxResult;

	return 0;
}