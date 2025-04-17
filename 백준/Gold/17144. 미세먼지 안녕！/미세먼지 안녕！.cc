#include <iostream>
#include <vector>
using namespace std;

int r, c, t;
int dust[51][51]{};
int diffusedDust[51][51]{};

int dy[8]{ 0, -1, 0, 1, 0, 1, 0, -1 };
int dx[8]{ 1, 0, -1, 0, 1, 0, -1, 0 };

vector<pair<int, int>> airPurifier;

void Diffusion() {
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			int remain = dust[i][j];
			int diffusionAmount = dust[i][j] / 5;

			for (int k = 0; k < 4; ++k) {
				int ny = dy[k] + i;
				int nx = dx[k] + j;

				if (ny < 0 || nx < 0 || ny >= r || nx >= c
					|| dust[ny][nx] == -1)
					continue;

				int acceptAmount = dust[ny][nx] / 5;
				diffusedDust[i][j] += acceptAmount;

				remain -= diffusionAmount;
			}
			diffusedDust[i][j] += remain;
		}
	}

	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j) {
			if (dust[i][j] != -1)
				dust[i][j] = diffusedDust[i][j];

			diffusedDust[i][j] = 0;
		}
}

void Purity(int y, int x, int dir) {

	int originDust = 0;

	while (1) {
		y += dy[dir];
		x += dx[dir];

		if (y < 0 || x < 0 || y >= r || x >= c) {
			y -= dy[dir];
			x -= dx[dir];

			++dir;
			continue;
		}

		if (dust[y][x] == -1)
			break;

		swap(dust[y][x], originDust);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c >> t;

	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j) {
			cin >> dust[i][j];

			if (dust[i][j] == -1)
				airPurifier.push_back({ i,j });
		}

	while (t--) {
		Diffusion();
		Purity(airPurifier[0].first, airPurifier[0].second, 0);
		Purity(airPurifier[1].first, airPurifier[1].second, 4);
	}

	int result = 0;

	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			if (dust[i][j] != -1)
				result += dust[i][j];

	cout << result;

	return 0;
}