#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		float x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		if (x1 == x2 && y1 == y2 && r1 == r2) {
			cout << "-1\n";
			continue;
		}

		float tempX = x1 - x2;
		float tempY = y1 - y2;
		float distance = sqrt(tempX * tempX + tempY * tempY);
		
		if (distance == r1 + r2 || distance == abs(r2 - r1))
			cout << "1\n";
		else if (distance > r1 + r2 || distance < abs(r2 - r1))
			cout << "0\n";
		else
			cout << "2\n";
	}

	return 0;
}