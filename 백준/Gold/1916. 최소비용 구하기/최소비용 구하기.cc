#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_CITY 1001
#define INF 1e9

vector<pair<int, int>> v[MAX_CITY];
int d[MAX_CITY]{};

void Dijkstra(int start) {
	d[start] = 0;
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int distance = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (d[cur] < distance)
			continue;

		for (int i = 0; i < v[cur].size(); ++i) {
			int next = v[cur][i].first;
			int nextDistance = distance + v[cur][i].second;

			if (d[next] > nextDistance) {
				d[next] = nextDistance;
				pq.push({ nextDistance, next });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, a, b;
	cin >> n >> m;
	
	for (int i = 0; i < m; ++i) {
		int start, end, value;
		cin >> start >> end >> value;
		
		v[start].push_back({ end, value });
	}

	for (int i = 0; i <= n; ++i)
		d[i] = INF;

	cin >> a >> b;

	Dijkstra(a);

	cout << d[b];

	return 0;
}