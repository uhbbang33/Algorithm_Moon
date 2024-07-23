#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[9]{};
bool used[9]{};

void Backtracking(int num) {
	if (num == m) {
		for (int i = 0; i < m; ++i)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			if (num > 0 && arr[num - 1] > i)
				continue;
			arr[num] = i;
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
	
	Backtracking(0);

	return 0;
}