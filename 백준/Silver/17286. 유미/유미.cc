#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

double Distance(pair<int, int> a, pair<int,int> b) {
	return sqrt((pow(a.first - b.first, 2) + pow(a.second - b.second, 2)));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	pair<int, int> arr[4]{};
	for (int i = 0; i < 4; ++i)
		cin >> arr[i].first >> arr[i].second;

	int order[3] = { 1,2,3 };
	double minSum = 1000.0;
	do {
		double sum = 0.0;
		sum += Distance(arr[0], arr[order[0]]);
		sum += Distance(arr[order[0]], arr[order[1]]);
		sum += Distance(arr[order[1]], arr[order[2]]);

		minSum = min(minSum, sum);
	} while (next_permutation(order, order + 3));

	cout << (int)(minSum);

	return 0;
}
