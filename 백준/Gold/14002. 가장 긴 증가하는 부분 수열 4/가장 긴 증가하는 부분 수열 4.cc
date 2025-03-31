#include <iostream>
#include <vector>
using namespace std;

int arr[1001]{};
int dp[1001]{};
int prevIndex[1001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int resultCnt = 0;
	int lastIndex = 0;

	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];

		for (int j = i - 1; j >= 0; --j) {
			if (arr[j] < arr[i]) {
				if (dp[i] > dp[j] + 1)
					continue;

				dp[i] = dp[j] + 1;
				prevIndex[i] = j;
			}
		}

		if (dp[i] > resultCnt) {
			resultCnt = dp[i];
			lastIndex = i;
		}
	}

	cout << resultCnt << "\n";

	vector<int> resultVec;
	while (lastIndex != 0) {
		resultVec.push_back(arr[lastIndex]);
		lastIndex = prevIndex[lastIndex];
	}

	for (int i = resultVec.size() - 1; i >= 0; --i)
		cout << resultVec[i] << " ";

	return 0;
}