#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		
		int dist = y - x;

		int temp = 1;
		int cnt = 0;

		while (dist >= temp) {
			dist -= temp;
			++cnt;

			if (dist >= temp) {
				dist -= temp;
				++cnt;
				++temp;	
			}
			if (dist < temp && dist > 0)
				++cnt;
		}

		cout << cnt << "\n";
	}

	return 0;
}