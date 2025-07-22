#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int parent[1001]{};

int GetParent(int num) {
	if (num == parent[num])
		return num;

	return parent[num] = GetParent(parent[num]);
}

void UnionParent(int a, int b) {
	a = GetParent(a);
	b = GetParent(b);

	if (a != b) parent[a] = b;
}

bool FindParent(int a, int b) {
	if (GetParent(a) == GetParent(b))
		return true;
	
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	vector<pair<int, pair<int,int>>> edge(m);

	for(int i =0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == b) continue;

		edge[i] = { c, {a,b} };
	}
	
	for (int i = 1; i <= n; ++i)
		parent[i] = i;

	sort(edge.begin(), edge.end());

	int result = 0;
	for (int i = 0; i < m; ++i) {
		int a = edge[i].second.first;
		int b = edge[i].second.second;

		if (!FindParent(a, b)) {
			result += edge[i].first;
			UnionParent(a, b);
		}
	}

	cout << result;

	return 0;
}