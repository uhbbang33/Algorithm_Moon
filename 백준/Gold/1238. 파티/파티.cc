#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9

vector<pair<int, int>> edge[10001]{};
int d[10001]{};
int result[1001]{};

void Dijkstra(int start) {
	d[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	pq.push({ 0, start });

	while (!pq.empty()) {
		int distance = pq.top().first;
		int cur = pq.top().second;

		pq.pop();

		if (distance > d[cur])
			continue;

		for (int i = 0; i < edge[cur].size(); ++i) {
			int nextDistance = distance + edge[cur][i].second;
			int next = edge[cur][i].first;

			if (d[next] > nextDistance) {
				d[next] = nextDistance;
				pq.push({nextDistance, next});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, x;	// 학생, 도로, 목적지
	cin >> n >> m >> x;

	for (int i = 0; i < m; ++i) {
		int start, end, t;
		cin >> start >> end >> t;

		edge[start].push_back({ end, t });
	}

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j)
			d[j] = INF;

		Dijkstra(i);

		result[i] = d[x];
	}
	
	int maxResult = 0;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j)
			d[j] = INF;

		Dijkstra(x);

		result[i] += d[i];

		if (result[i] < INF)
			maxResult = max(result[i], maxResult);
	}

	cout << maxResult;

	return 0;
}