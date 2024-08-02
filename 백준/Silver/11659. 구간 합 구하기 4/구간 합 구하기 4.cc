#include <iostream>

using namespace std;

long long arr[100001]{};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int num;
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> num;
		sum += num;
		arr[i] = sum;
	}
	
	int startNum, endNum;
	for (int i = 0; i < m; ++i) {
		cin >> startNum >> endNum;
		cout << arr[endNum] - arr[startNum-1] << "\n";
	}

	return 0;
}