#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 100000000

int n;
vector<pair<int, int>> edge[200001]{}; // 연결된 정점, 거리
int dp[801]{};
bool visited[801]{};

void InitArr() {
	for (int i = 1; i <= n; ++i) {
		dp[i] = INF;
		visited[i] = false;
	}
}

void Dijkstra(int start) {
	dp[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;	// 가중치, 정점
	pq.push({ 0 , start });

	while (!pq.empty()) {
		int distance = pq.top().first;
		int curVertex = pq.top().second;
		pq.pop();

		visited[curVertex] = true;

		if (distance > dp[curVertex])
			continue;

		for (int i = 0; i < edge[curVertex].size(); ++i) {
			int nextVertex = edge[curVertex][i].first;
			int nextDistance = distance + edge[curVertex][i].second;

			if (visited[nextVertex]) continue;

			if (nextDistance < dp[nextVertex]) {
				dp[nextVertex] = nextDistance;
				pq.push({ nextDistance, nextVertex });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int e;
	cin >> n >> e;

	for (int i = 0; i < e; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		edge[a].push_back({ b,c });
		edge[b].push_back({ a,c });
	}
	
	int v1, v2;
	cin >> v1 >> v2;

	InitArr();
	Dijkstra(1);
	int one_V1_N = dp[v1];
	int one_V2_N = dp[v2];

	InitArr();
	Dijkstra(v1);
	one_V1_N += dp[v2];
	one_V2_N += dp[n];

	InitArr();
	Dijkstra(v2);
	one_V1_N += dp[n];
	one_V2_N += dp[v1];

	int result = min(one_V1_N, one_V2_N);

	if (result >= INF)
		cout << "-1";
	else
		cout << result;

	return 0;
}