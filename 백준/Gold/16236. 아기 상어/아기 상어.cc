#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

#define BABYSHARK 9

// y, x, distance
typedef tuple<int, int, int> myTuple;

int arr[21][21]{};

int n = 0;
int babySharkSize = 2;
int eatenFish = 0;
int resultTime = 0;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

pair<int, int> FindNearestFish(pair<int, int> start) {
	queue<myTuple> q;
	priority_queue<myTuple, vector<myTuple>, greater<myTuple>> eadibleFishs;

	bool visited[21][21]{};
	q.push({ start.first, start.second, 0 });
	visited[start.first][start.second] = true;

	while (!q.empty()) {
		myTuple t = q.front();
		int curY = get<0>(t);
		int curX = get<1>(t);
		int dist = get<2>(t);

		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = dy[i] + curY;
			int nx = dx[i] + curX;

			if (ny < 0 || nx < 0 || ny >= n || nx >= n
				|| visited[ny][nx]
				|| arr[ny][nx] > babySharkSize)
				continue;

			visited[ny][nx] = true;

			if (arr[ny][nx] < babySharkSize && arr[ny][nx] > 0)
				eadibleFishs.push({ dist+ 1, ny, nx });

			q.push({ ny,nx, dist + 1 });
		}
	}

	if (eadibleFishs.empty())
		return { -1, -1 };

	int dist = get<0>(eadibleFishs.top());
	int y = get<1>(eadibleFishs.top());
	int x = get<2>(eadibleFishs.top());

	resultTime += dist;
	return { y,x };
}

void Func(pair<int, int> start) {
	while (1) {
		pair<int, int> nextTarget = FindNearestFish(start);
		if (nextTarget.first == -1)
			break;

		int y = nextTarget.first;
		int x = nextTarget.second;
		arr[y][x] = 0;

		start = nextTarget;
		++eatenFish;

		if (eatenFish == babySharkSize) {
			++babySharkSize;
			eatenFish = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	pair<int, int> sharkFirstLocation;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];

			if (arr[i][j] == BABYSHARK) {
				sharkFirstLocation = make_pair(i, j);
				arr[i][j] = 0;
			}
		}

	Func(sharkFirstLocation);

	cout << resultTime;

	return 0;
}