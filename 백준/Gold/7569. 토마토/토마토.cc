#include <iostream>
#include <queue>
using namespace std;

int arr[101][101][101]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n, h;
	cin >> m >> n >> h;

	queue<pair<int, pair<int, int>>> q;
	int zeroTomato = 0;
	
	for (int i = 0; i < h; ++i) 
		for (int j = 0; j < n; ++j) 
			for (int k = 0; k < m; ++k) {
				cin >> arr[i][j][k];

				if (arr[i][j][k] == 1) 
					q.push({ i,{j, k} });
				else if (arr[i][j][k] == 0)
					++zeroTomato;
			}

	int dz[6] = { 0, 0, 0, 0, 1, -1 };
	int dy[6] = { 1, -1, 0, 0, 0, 0 };
	int dx[6] = { 0, 0, -1, 1, 0, 0 };
	
	int result = 0;
	int oneDaySize = q.size();
	
	while (!q.empty()) {
		int height = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;

		q.pop();
		
		for (int i = 0; i < 6; ++i) {
			int nz = height + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (nz < 0 || nz >= h || ny < 0 || ny >= n || nx < 0 || nx >= m)
				continue;

			if (arr[nz][ny][nx] == 0) {
				q.push({ nz, {ny, nx} });
				arr[nz][ny][nx] = 1;

				--zeroTomato;
			}
		}
		--oneDaySize;

		if (oneDaySize == 0 && !q.empty()) {
			++result;
			oneDaySize = q.size();
		}
	}

	if (zeroTomato == 0)
		cout << result;
	else
		cout << "-1";

	return 0;
}