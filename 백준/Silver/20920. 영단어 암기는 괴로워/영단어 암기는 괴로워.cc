#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	map<string, int> myMap;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		
		if (s.length() < m)
			continue;

		++myMap[s];
	}

	vector<pair<string, int>> v;
	for (auto m : myMap)
		v.push_back(m);

	sort(v.begin(), v.end(),
		[](const pair<string, int>& a, const pair<string, int>& b)
		{
			if (a.second != b.second)
				return a.second > b.second;
			if (a.first.length() != b.first.length())
				return a.first.length() > b.first.length();
			return a < b;
		});

	for (auto i : v)
		cout << i.first << "\n";

	return 0;
}