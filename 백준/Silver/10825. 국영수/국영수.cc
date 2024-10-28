#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, pair<int, pair<int, string>>> pair_t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	vector<pair_t> v;

	for (int i = 0; i < n; ++i) {
		string name;
		int k, e, m;
		cin >> name >> k >> e >> m;

		v.push_back({ k,{e,{m, name}} });
	}
	
	sort(v.begin(), v.end(), [](pair_t a, pair_t b) -> bool {
		if (a.first == b.first) {
			if (a.second.first == b.second.first) {
				if (a.second.second.first == b.second.second.first)
					return a.second.second.second < b.second.second.second;
				return a.second.second.first > b.second.second.first;
			}
			return a.second.first < b.second.first;
		}
		
		return a.first > b.first;

		});

	for (int i = 0; i < n; ++i) {
		//cout << v[i].first << " " << v[i].second.first << " "
		//	<< v[i].second.second.first << " " << v[i].second.second.second;

		cout << v[i].second.second.second << "\n";
	}


	return 0;
}