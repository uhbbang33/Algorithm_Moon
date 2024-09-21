#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	int maxX = -1e5, maxY = -1e5;
	int minX = 1e5, minY = 1e5;

	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		maxX = max(x, maxX);
		maxY = max(y, maxY);
		minX = min(x, minX);
		minY = min(y, minY);
	}
	
	cout << (maxX - minX) * (maxY - minY);

	return 0;
}