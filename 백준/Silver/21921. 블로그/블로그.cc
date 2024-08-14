#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[250001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	cin >> n >> x;

	long long maxResult = 0;
	int longTerm = 0;

	long long curSum = 0;
	int startP = 0;
	int num;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		arr[i] = num;

		curSum += num;
		if (i > x - 1) {
			curSum -= arr[startP];
			++startP;
		}

		if (maxResult < curSum) {
			longTerm = 1;
			maxResult = curSum;
		}
		else if (maxResult == curSum)
			++longTerm;
	}
	
	if (maxResult != 0)
		cout << maxResult << "\n" << longTerm;
	else
		cout << "SAD" << "\n";

	return 0;
}