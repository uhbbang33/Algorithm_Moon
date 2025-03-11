#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1000000000

vector<pair<int,int>> bus[1001];
pair<int, int> dp[1001]{};	// 최소비용, 직전 정점

void Dijkstra(int start, int end) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // cost, 정점
	pq.push({ 0, start });

	dp[start] = { 0,0 };
	
	while (!pq.empty()) {
		int curCost = pq.top().first;
		int curCity = pq.top().second;
		pq.pop();

		if (curCity == end)
			return;

		for (int i = 0; i < bus[curCity].size(); ++i) {
			int nextCity = bus[curCity][i].first;
			int nextCost = curCost + bus[curCity][i].second;

			if (dp[nextCity].first <= nextCost) continue;

			dp[nextCity].first = nextCost;
			dp[nextCity].second = curCity;
			pq.push({ nextCost, nextCity });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int start, end, cost;
		cin >> start >> end >> cost;

		bus[start].push_back({ end, cost });
	}

	for (int i = 1; i <= n; ++i)
		dp[i] = { INF, 0 };

	int startCity, endCity;
	cin >> startCity >> endCity;

	Dijkstra(startCity, endCity);

	cout << dp[endCity].first << "\n";

	vector<int> result;
	for (int i = endCity; i != 0; i = dp[i].second)
		result.push_back(i);

	cout << result.size() << "\n";

	for (int i = result.size() - 1; i >= 0; --i)
		cout << result[i] << " ";

	return 0;
}