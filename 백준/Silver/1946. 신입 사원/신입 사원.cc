#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;

		vector<pair<int, int>> score(n);
		for (int j = 0; j < n; ++j)
			cin >> score[j].first >> score[j].second;
		
		sort(score.begin(), score.end());

		int result = 0;
		int temp = score[0].second;
		for (int j = 0; j < n; ++j) {
			if (temp >= score[j].second) {
				++result;
				temp = score[j].second;
			}
		}

		cout << result << "\n";
	}

	return 0;
}