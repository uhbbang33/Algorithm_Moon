#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[1025][1025]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];
	
	while (n != 1) {
		for (int i = 0; i < n; i += 2) {
			for (int j = 0; j < n; j += 2) {
				priority_queue<int> pq;
				pq.push(arr[i][j]);
				pq.push(arr[i + 1][j]);
				pq.push(arr[i][j + 1]);
				pq.push(arr[i + 1][j + 1]);

				pq.pop();
				arr[i / 2][j / 2] = pq.top();
			}
		}
		n /= 2;
	}

	cout << arr[0][0];

	return 0;
}