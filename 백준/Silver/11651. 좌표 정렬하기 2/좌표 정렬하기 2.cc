#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> p[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> p[i].second >> p[i].first;
	sort(p, p + n);

	for (int i = 0; i < n; ++i)
		cout << p[i].second << " " << p[i].first << "\n";

	return 0;
}