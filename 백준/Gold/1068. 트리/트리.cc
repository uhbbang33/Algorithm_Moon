#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int arr[51]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> parentVec(n);
	int rootNode = 0;

	for (int node = 0; node < n; ++node) {
		int parent;
		cin >> parent;

		if (parent == -1) {
			rootNode = node;
			continue;
		}

		parentVec[parent].push_back(node);
	}

	int removeNode;
	cin >> removeNode;

	queue<int> q;
	q.push(removeNode);

	while (!q.empty()) {
		int parent = q.front();
		q.pop();

		for (int i = 0; i < parentVec[parent].size(); ++i)
			q.push(parentVec[parent][i]);

		parentVec[parent] = { -1 };
	}

	int leafNode = 0;
	for (int i = 0; i < n; ++i)
		if (parentVec[i].size() == 0
			|| (parentVec[i].size() == 1 && parentVec[i][0] == removeNode))
			++leafNode;

	cout << leafNode;

	return 0;
}