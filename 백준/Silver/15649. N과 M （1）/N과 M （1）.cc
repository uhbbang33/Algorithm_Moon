#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[9]{};
bool used[9]{};

void BackTracking(int num) {
	if (num == m) {
		for (int i = 0; i < m; ++i)
			cout << arr[i] << " ";

		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			arr[num] = i;
			used[i] = true;
			BackTracking(num + 1);
			used[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	BackTracking(0);

	return 0;
}