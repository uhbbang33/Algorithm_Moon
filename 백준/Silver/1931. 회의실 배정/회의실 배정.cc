#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n = 0;
	cin >> n;

	vector<pair<int, int>> p(n);
	for (int i = 0; i < n; ++i)
		cin >> p[i].second >> p[i].first;

	sort(p.begin(), p.end());

	int result = 1;
	int temp = p[0].first;

	for (int i = 1; i < n; ++i) {
		if (temp <= p[i].second) {
			temp = p[i].first;
			++result;
		}
	}
	cout << result;


	return 0;
}