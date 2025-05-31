#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	pair<int,int> a[51]{};
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a, a + n);

	int p[51]{};
	for (int i = 0; i < n; ++i)
		p[a[i].second] = i;

	for (int i = 0; i < n; ++i)
		cout << p[i] << " ";

	return 0;
}