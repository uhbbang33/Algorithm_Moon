#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> p[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> p[i].first >> p[i].second;
	
	sort(p, p + n,
		[](pair<int, int> a, pair<int, int> b) {
			if (a.first == b.first)
				return a.second < b.second;
			else return a.first < b.first;
		});

	for (int i = 0; i < n; ++i)
		cout << p[i].first << " " << p[i].second << "\n";

	return 0;
}