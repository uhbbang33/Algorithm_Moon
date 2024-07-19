#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//https://www.acmicpc.net/problem/2805

int n = 0, m = 0;
vector<int> treeHeight;

int FindMaxHeight(int start, int end) {
	int maxHeight = 0;

	while (start <= end) {
		int mid = (start + end) / 2;
		long long takeTree = 0;

		for (int a : treeHeight)
			if (a > mid)
				takeTree += a - mid;

		if (takeTree < m)
			end = mid - 1;
		else{
			maxHeight = mid;
			start = mid + 1;
		}
	}
	return maxHeight;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	int num = 0;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		treeHeight.push_back(num);
	}
	sort(treeHeight.begin(), treeHeight.end());

	cout << FindMaxHeight(0, treeHeight.back());

	return 0;
}