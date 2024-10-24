#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_VERTEX 20001
#define MAX_EDGE 300001
#define INF 1e9

vector<pair<int, int>> edge[MAX_EDGE];
int d[MAX_VERTEX]{};

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
			int next = edge[cur][i].first;
			int nextDistance = distance + edge[cur][i].second;

			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push({ nextDistance, next });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int v, e, k;
	cin >> v >> e >> k;
	
	for (int i = 0; i < e; ++i) {
		int u, v, w;
		cin >> u >> v >> w;

		edge[u].push_back({ v, w });
	}

	for (int i = 0; i <= v; ++i)
		d[i] = INF;

	Dijkstra(k);

	for (int i = 1; i <= v; ++i) {
		if (d[i] != INF)
			cout << d[i] << "\n";
		else
			cout << "INF" << "\n";
	}

	return 0;
}