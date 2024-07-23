#include <iostream>

using namespace std;

int n, m;
int arr[8]{};

void Backtracking(int num) {
	if (num == m) {
		for (int i = 0; i < m; ++i)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	
	for (int i = 1; i <= n; ++i) {
			arr[num] = i;
			Backtracking(num + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	
	Backtracking(0);

	return 0;
}