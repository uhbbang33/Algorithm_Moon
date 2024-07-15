#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int BinarySearch(int start, int end, int budget, vector<int> request) {
	int max = 0;

	while (start <= end) {
		int mid = (start + end) / 2;

		int sum = 0;
		for (int i = 0; i < request.size(); ++i) {
			if (request[i] <= mid)
				sum += request[i];
			else
				sum += mid;
		}
		
		if (sum == budget)
			return mid;

		if (sum < budget) {
			start = mid + 1;
			
			if (max < mid)
				max = mid;
		}

		if (sum > budget)
			end = mid - 1;
	}

	return max;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;
	
	vector<int> request(n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> request[i];
		sum += request[i];
	}
	sort(request.begin(), request.end());

	int budget = 0;
	cin >> budget;

	if (sum <= budget) 
		cout << request.back();
	else
		cout << BinarySearch(0, request.back(), budget, request);

	return 0;
}