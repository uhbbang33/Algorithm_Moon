#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	pair<int, int> a[2], b[2];
	cin >> a[0].first >> b[0].first;
	++a[0].second;
	++b[0].second;

	for (int i = 1; i < 3; ++i) {
		int x, y;
		cin >> x >> y;
		
		if (x == a[0].first)
			++a[0].second;
		else {
			a[1].first = x;
			++a[1].second;
		}
		if (y == b[0].first)
			++b[0].second;
		else {
			b[1].first = y;
			++b[1].second;
		}
	}

	for (int i = 0; i < 2; ++i)
		if (a[i].second == 1)
			cout << a[i].first << " ";
	for (int i = 0; i < 2; ++i)
		if (b[i].second == 1)
			cout << b[i].first << " ";
	

	return 0;
}