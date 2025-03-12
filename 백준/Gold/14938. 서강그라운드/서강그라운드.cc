#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1000000000

// 지역 개수, 수색범위, 길의 개수
int n, m, r;
int t[101]{};
int result = 0;

vector<pair<int, int>> edge[101]{};
int dp[101]{};

int Dijkstra(int start) {
	for (int i = 1; i <= n; ++i)
		dp[i] = INF;
	dp[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, start });
	
	while (!pq.empty()) {
		int length = pq.top().first;
		int curVertex = pq.top().second;
		pq.pop();

		for (int i = 0; i < edge[curVertex].size(); ++i) {
			int nextVertex = edge[curVertex][i].first;
			int nextLength = length + edge[curVertex][i].second;

			if (dp[nextVertex] > nextLength) {
				dp[nextVertex] = nextLength;
				pq.push({ dp[nextVertex], nextVertex });
			}
		}
	}

	int sum = 0;
	for (int i = 1; i <= n; ++i) 
		if (dp[i] <= m)
			sum += t[i];

	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> r;

	for (int i = 1; i <= n; ++i)
		cin >> t[i];

	for (int i = 0; i < r; ++i) {
		int a, b, l;
		cin >> a >> b >> l;

		edge[a].push_back({ b,l });
		edge[b].push_back({ a,l });
	}

	for (int i = 1; i <= n; ++i)
		result = max(result, Dijkstra(i));

	cout << result;

	return 0;
}