#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_CITY_CNT 300001
#define CITY_DISTANCE 1

int k;

priority_queue<int, vector<int>, greater<>> result;
vector<vector<int>> edge;
vector<int> visited;

void Dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // 거리, 정점
	pq.push({ 0, start });

	visited[start] = true;

	while (!pq.empty()) {
		int curDistance = pq.top().first;
		int curCity = pq.top().second;
		pq.pop();

		for (int i = 0; i < edge[curCity].size(); ++i) {
			int nextDistance = curDistance + CITY_DISTANCE;
			int nextCity = edge[curCity][i];

			if (visited[nextCity])
				continue;
			
			visited[nextCity] = true;

			if (nextDistance == k)
				result.push(nextCity);
			else
				pq.push({ nextDistance, nextCity });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, x;
	cin >> n >> m >> k >> x;

	edge.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		
		edge[a].push_back(b);
	}

	Dijkstra(x);

	if (result.size() == 0)
		cout << "-1";
	else {
		while (!result.empty()) {
			cout << result.top() << "\n";
			result.pop();
		}
	}
	return 0;
}