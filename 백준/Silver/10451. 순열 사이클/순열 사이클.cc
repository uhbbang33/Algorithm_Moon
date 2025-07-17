#include <iostream>
using namespace std;

int arr[1001]{};
bool visited[1001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		for (int i = 1; i <= n; ++i) {
			cin >> arr[i];
			visited[i] = false;
		}

		int cycle = 0;
		for (int i = 1; i <= n; ++i) {
			if (visited[i])
				continue;

			visited[i] = true;
			int cur = arr[i];
			
			while (!visited[cur]) {
				visited[cur] = true;
				cur = arr[cur];
			}
			++cycle;
		}
		cout << cycle << "\n";
	}

	return 0;
}