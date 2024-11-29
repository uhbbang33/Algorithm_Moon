#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define HOUSE 1
#define CHICKEN 2
#define MAX 10000000

int n, m, result = MAX;
int arr[51][51]{};
vector<pair<int, int>> chicken, house, selected;

int CalculateDist() {
	int cityDist = 0;

	for (int i = 0; i < house.size(); ++i) {
		int houseY = house[i].first;
		int houseX = house[i].second;

		int minDist = MAX;

		for (int j = 0; j < selected.size(); ++j) {
			int chickenY = selected[j].first;
			int chickenX = selected[j].second;

			minDist = min(minDist,
				abs(houseY - chickenY) + abs(houseX - chickenX));
		}
		cityDist += minDist;
	}

	return cityDist;
}

void SelectChicken(int idx, int cnt) {
	if (cnt == m) {
		result = min(result, CalculateDist());
		return;
	}

	for (int i = idx; i < chicken.size(); ++i) {
		selected.push_back(chicken[i]);
		SelectChicken(i + 1, cnt + 1);
		selected.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];

			if (arr[i][j] == CHICKEN)
				chicken.push_back({ i, j });
			else if (arr[i][j] == HOUSE)
				house.push_back({ i, j });
		}
	
	SelectChicken(0, 0);
	
	cout << result;

	return 0;
}