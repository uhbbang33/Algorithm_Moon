#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;

int arr[8]{};
bool used[8]{};

void Backtracking(int num) {
	if (num == m) {
		for (int i = 0; i < m; ++i)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	
	for (int i = 1; i <= n; ++i) {
			if (num > 0 && arr[num - 1] > v[i-1])
				continue;
			arr[num] = v[i - 1];
			Backtracking(num + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	v.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());

	Backtracking(0);

	return 0;
}