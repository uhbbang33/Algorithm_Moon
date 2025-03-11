#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1000000000

typedef pair<int, vector<int>> myType;

vector<pair<int,int>> bus[1001];
int dp[1001]{};

vector<int> Dijkstra(int start, int end) {
	vector<int> v;
	v.push_back(start);

	priority_queue<myType, vector<myType>, greater<>> pq; // cost, 정점
	pq.push({ 0, v });

	dp[start] = 0;
	
	while (!pq.empty()) {
		int curCost = pq.top().first;
		vector<int> curVec = pq.top().second;
		int curCity = curVec.back();

		if (curCity == end)
			return curVec;

		pq.pop();

		for (int i = 0; i < bus[curCity].size(); ++i) {
			int nextCity = bus[curCity][i].first;
			int nextCost = curCost + bus[curCity][i].second;

			if (dp[nextCity] <= nextCost) continue;
			dp[nextCity] = nextCost;

			curVec.push_back(nextCity);
			pq.push({ nextCost, curVec });
			curVec.pop_back();
		}
	}

	return v;
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
		dp[i] = INF;

	int startCity, endCity;
	cin >> startCity >> endCity;

	vector<int> result = Dijkstra(startCity, endCity);
	
	cout << dp[endCity] << "\n";
	cout << result.size() << "\n";

	for (int r : result)
		cout << r << " ";

	return 0;
}