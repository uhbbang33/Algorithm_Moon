#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 4000001

vector<bool> visited(MAX_N, true);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	if (n == 1) {
		cout << "0";
		return 0;
	}

	for (int i = 2; i * i <= n; ++i) {
		if (visited[i] == false) continue;
		
		for (int j = i * i; j <= n; j += i) 
			visited[j] = false;
	}

	vector<int> primeVec;
	for (int i = 2; i <= n; ++i) {
		if (visited[i])
			primeVec.push_back(i);
	}

	int p1 = 0, p2 = 1;
	int sum = primeVec[p1];
	int result = 0;

	while (p1 < p2) {
		if (sum < n) {
			if (p2 >= primeVec.size())
				break;
			sum += primeVec[p2];
			++p2;
		}
		else if (sum > n) {
			sum -= primeVec[p1];
			++p1;
		}

		if (sum == n) {
			++result;
			sum -= primeVec[p1];
			++p1;
		}
	}

	cout << result;

	return 0;
}