#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int computer, connected;
bool visited[101];
vector<pair<int, int>> v;
int result = 0;

int dfs(int x) {
	visited[x] = true;

	for (int i = 0; i < connected; ++i) {
		if (v[i].first == x && !visited[v[i].second]) {
			++result;
			dfs(v[i].second);
		}
		else if (v[i].second == x && !visited[v[i].first]) {
			++result;
			dfs(v[i].first);
		}
	}

	return result;
}

int main() {
	cin >> computer >> connected;
	v.resize(connected);

	for (int i = 0; i < connected; ++i)
		cin >> v[i].first >> v[i].second;

	cout << dfs(1);
	
	return 0;
}