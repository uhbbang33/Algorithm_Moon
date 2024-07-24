#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int v[9]{};
int arr[9]{};

void Backtracking(int num) {
	if (num == m) {
		for (int i = 0; i < m; ++i)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	int temp = 0;
	for (int i = 1; i <= n; ++i) {
		if (temp != v[i - 1]) {
			arr[num] = v[i - 1];
			temp = arr[num];

			Backtracking(num + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v, v + n);

	Backtracking(0);

	return 0;
}