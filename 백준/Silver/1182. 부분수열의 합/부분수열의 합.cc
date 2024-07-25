#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, s;
int arr[21]{};
int resultCnt = 0;

void Backtracking(int num, int sum) {
	if (num >= n)
		return;

	sum += arr[num];
	if (sum == s)
		++resultCnt;

	Backtracking(num + 1, sum);
	Backtracking(num + 1, sum - arr[num]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> s;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr, arr + n);

	Backtracking(0, 0);

	cout << resultCnt;

	return 0;
}