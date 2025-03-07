#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX_CITY_CNT 300001
#define CITY_DISTANCE 1

int k;

vector<int> resultVec;
vector<int> edge[MAX_CITY_CNT];
bool visited[MAX_CITY_CNT]{};

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
				resultVec.push_back(nextCity);
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

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		
		edge[a].push_back(b);
	}

	Dijkstra(x);

	if (resultVec.size() == 0)
		cout << "-1";
	else {
		sort(resultVec.begin(), resultVec.end());
		for (int result : resultVec)
			cout << result << "\n";
	}

	return 0;
}