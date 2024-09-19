#include <iostream>
using namespace std;

int n = 0;
int arr[11]{};
int oper[4]{};
int maxResult = -1e9;
int minResult = 1e9;

void Func(int result, int index) {
	if (index == n) {
		maxResult = max(maxResult, result);
		minResult = min(minResult, result);
		return;
	}

	for (int i = 0; i < 4; ++i) {
		if (oper[i] > 0) {
			--oper[i];

			if(i == 0)
				Func(result + arr[index], index + 1);
			else if(i == 1)
				Func(result - arr[index], index + 1);
			else if(i ==2)
				Func(result * arr[index], index + 1);
			else 
				Func(result / arr[index], index + 1);

			++oper[i];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	for (int i = 0; i < 4; ++i)
		cin >> oper[i];

	Func(arr[0], 1);

	cout << maxResult << "\n" << minResult;

	return 0;
}