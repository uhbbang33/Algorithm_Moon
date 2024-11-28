#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, b;
	cin >> n >> a >> b;
	
	bool possibleSubway = false;
	if (b - n >= 0)
		possibleSubway = true;

	if (!possibleSubway)
		cout << "Bus";
	else {
		if (b > a)
			cout << "Bus";
		else if (b == a)
			cout << "Anything";
		else
			cout << "Subway";
	}
	return 0;
}