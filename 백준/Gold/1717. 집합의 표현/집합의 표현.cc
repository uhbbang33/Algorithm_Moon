#include <iostream>
#include <algorithm>
using namespace std;

int parent[1000001]{};

int GetParent(int num) {
	if (parent[num] == num)
		return num;

	parent[num] = GetParent(parent[num]);

	return parent[num];
}

void UnionParent(int a, int b) {
	a = GetParent(a);
	b = GetParent(b);

	if (a > b)
		parent[a] = b;
	else
		parent[b] = a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; ++i)
		parent[i] = i;

	for (int i = 0; i < m; ++i) {
		bool oper;
		int a, b;
		cin >> oper >> a >> b;

		if (oper) {
			if (GetParent(a) == GetParent(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else {
			if (a == b)
				continue;

			UnionParent(a, b);
		}
	}

	return 0;
}