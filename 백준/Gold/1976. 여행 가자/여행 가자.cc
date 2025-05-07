#include <iostream>
#include <vector>
using namespace std;

int parent[201]{};

int FindParent(int x) {
	if (parent[x] != x)
		parent[x] = FindParent(parent[x]);

	return parent[x];
}

void UnionParent(int a, int b) {
	a = FindParent(a);
	b = FindParent(b);

	if (a != b)
		parent[b] = a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		parent[i] = i;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			bool connect;
			cin >> connect;

			if (connect == true)
				UnionParent(i, j);
		}
	}

	vector<int> plan(m);
	for (int i = 0; i < m; ++i)
		cin >> plan[i];

	int root = FindParent(plan[0]);
	for (int i = 1; i < m; ++i)
		if (FindParent(plan[i]) != root) {
			cout << "NO";
			return 0;
		}

	cout << "YES";

	return 0;
}