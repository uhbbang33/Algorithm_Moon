#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 10001

vector<pair<int, int>> v[MAX_N];
bool visited[MAX_N]{};
int maxResult = 0;
int maxNode = 0;

void DFS(int curNode, int curDist) {
	if (visited[curNode])
		return;
	visited[curNode] = true;

	if (maxResult < curDist) {
		maxResult = curDist;
		maxNode = curNode;
	}

	for (int i = 0; i < v[curNode].size(); ++i) {
		int nextNode = v[curNode][i].first;
		int nextCost = curDist + v[curNode][i].second;
		DFS(nextNode, nextCost);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; ++i) {
		int f, c, dist;
		cin >> f >> c >> dist;

		v[f].push_back({ c, dist });
		v[c].push_back({ f, dist });
	}

	DFS(1, 0);
	for (int i = 0; i <= n; ++i)
		visited[i] = false;
	maxResult = 0;

	DFS(maxNode, 0);

	cout << maxResult;
	
	return 0;
}