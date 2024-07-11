#include <iostream>
using namespace std;

int n = 0;
char graph[11][11]{};
char resultGraph[11][11]{};

int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dy[8] = { 1, 1, 1, 0, 0, -1,-1, -1 };

int CountStar(int a, int b) {
	int star = 0;

	for (int i = 0; i < 8; ++i) {
		int nx = dx[i] + b;
		int ny = dy[i] + a;

		if (nx < 0 || ny < 0 || nx >= n || ny >= n)
			continue;

		if (graph[ny][nx] == '*')
			++star;
	}

	return star;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> graph[i][j];

	bool isFind = false;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> resultGraph[i][j];
			if (resultGraph[i][j] == 'x') {
				if (graph[i][j] == '*')
					isFind = true;

				resultGraph[i][j] = CountStar(i, j) + '0';
			}
		}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (isFind && graph[i][j] == '*')
				cout << '*';
			else
				cout << resultGraph[i][j];
		}
		cout << "\n";
	}

	return 0;
}