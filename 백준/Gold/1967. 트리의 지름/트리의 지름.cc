#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 10001

vector<pair<int, int>> v[MAX_N];
bool visited[MAX_N]{};
int maxResult = 0;

void DFS(int curNode, int curCost) {
	for (int i = 0; i < v[curNode].size(); ++i) {
		int nextNode = v[curNode][i].first;
		int nextCost = curCost + v[curNode][i].second;

		if (visited[nextNode])
			continue;

		visited[nextNode] = true;

		if (v[nextNode].size() == 1)
			maxResult = max(maxResult, nextCost);
		else 
			DFS(nextNode, nextCost);
		
		visited[nextNode] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; ++i) {
		int f, c, cost;
		cin >> f >> c >> cost;

		v[f].push_back({ c, cost });
		v[c].push_back({ f, cost });
	}

	for (int i = 1; i <= n; ++i)
		if (v[i].size() == 1) {
			visited[i] = true;
			DFS(i, 0);
		}

	cout << maxResult;
	
	return 0;
}