#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int x1, x2, y1, y2, n;
		cin >> x1 >> y1 >> x2 >> y2 >> n;

		int result = 0;
		for (int i = 0; i < n; ++i) {
			int cx, cy, r;
			cin >> cx >> cy >> r;

			bool isInStartPlanet = false;
			bool isInTarget = false;

			int diffX = abs(cx - x1);
			int diffY = abs(cy - y1);
			int distance = sqrt(diffX* diffX + diffY * diffY);
			if(distance < r)
				isInStartPlanet = true;

			diffX = abs(cx - x2);
			diffY = abs(cy - y2);
			distance = sqrt(diffX * diffX + diffY * diffY);
			if (distance < r)
				isInTarget = true;

			if (isInStartPlanet && isInTarget)
				continue;
			else if (isInStartPlanet || isInTarget)
				++result;
		}

		cout << result << "\n";
	}

	return 0;
}