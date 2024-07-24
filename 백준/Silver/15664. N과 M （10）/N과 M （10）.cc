#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int v[9]{};
int arr[9]{};
bool used[9]{};

void Backtracking(int num) {
	if (num == m) {
		for (int i = 0; i < m; ++i)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	int temp = 0;
	for (int i = 1; i <= n; ++i) {
		if (!used[i] && temp != v[i - 1]) {
			if (num > 0 && arr[num - 1] > v[i-1])
				continue;
			arr[num] = v[i - 1];
			temp = arr[num];

			used[i] = true;
			Backtracking(num + 1);
			used[i] = false;
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