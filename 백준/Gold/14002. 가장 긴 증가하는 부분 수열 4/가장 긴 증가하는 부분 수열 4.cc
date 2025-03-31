#include <iostream>
#include <vector>
using namespace std;

int arr[1001]{};
pair<int, vector<int>> dp[1001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> maxVec;
	
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		for (int j = i - 1; j >= 0; --j) {
			if (arr[j] < arr[i]) {
				if (dp[i].first > dp[j].first + 1)
					continue;

				dp[i].first = dp[j].first + 1;
				dp[i].second = dp[j].second;
				
				dp[i].second.push_back(arr[i]);
			}
		}
		
		if (dp[i].first > maxVec.size()) 
			maxVec = dp[i].second;
	}

	cout << maxVec.size() << "\n";
	for (int a : maxVec) {
		cout << a << " ";
	}


	return 0;
}