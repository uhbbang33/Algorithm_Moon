#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int parent[10001]{};

int GetParent(int x) {
	if (parent[x] == x)
		return x;

	return parent[x] = GetParent(parent[x]);
}

void UnionParent(int a, int b) {
	a = GetParent(a);
	b = GetParent(b);
	
	if (a != b)
		parent[b] = a;
}

bool UnionFind(int a, int b) {
	if (GetParent(a) == GetParent(b))
		return true;
	
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int v, e;
	cin >> v >> e;
	
	for (int i = 1; i <= v; ++i)
		parent[i] = i;

	vector<pair<int, pair<int, int>>> vec;

	for (int i = 0; i < e; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		vec.push_back({ c, {a,b} });
	}
	sort(vec.begin(), vec.end());

	int result = 0;
	for (int i = 0; i < e; ++i) {
		if (!UnionFind(vec[i].second.first, vec[i].second.second)) {
			UnionParent(vec[i].second.first, vec[i].second.second);
			result += vec[i].first;
		}
	}

	cout << result;

	return 0;
}
