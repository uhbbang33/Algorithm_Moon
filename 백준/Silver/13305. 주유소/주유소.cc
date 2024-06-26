#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;
	
	vector<long long> dist(n);
	for (int i = 0; i < n - 1; ++i)
		cin >> dist[i];
	
	vector<long long> price(n);
	for (int i = 0; i < n; ++i)
		cin >> price[i];

	long long result = 0;
	for (int i = 0; i < n; ++i) {
		int tempDist = dist[i];
		int jump = 0;
		for (int j = i+1; j < n; ++j) {
			if (price[i] < price[j]) {
				tempDist += dist[j];
				++jump;
			}
			else break;
		}
		result += tempDist * price[i];
		i += jump;
	}

	cout << result;

	return 0;
}