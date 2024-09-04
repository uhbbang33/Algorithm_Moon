#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int p;
	cin >> p;

	int soft = 0, em = 0, ai = 0, fresh = 0;

	int g, c, n;
	while(p--) {
		cin >> g >> c >> n;
		if (g == 1) {
			++fresh;
			continue;
		}
		
		if (c == 1 || c == 2)
			++soft;
		else if (c == 3)
			++em;
		else if (c == 4)
			++ai;
	}

	cout << soft << "\n" << em << "\n" << ai << "\n" << fresh;

	return 0;
}