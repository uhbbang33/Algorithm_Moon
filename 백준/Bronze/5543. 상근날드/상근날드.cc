#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int burger[3] = {};
	int cola, sida;
	cin >> burger[0] >> burger[1] >> burger[2] >> cola >> sida;
	
	sort(burger, burger + 3);
	cout << min(cola,sida) + burger[0] - 50;

	return 0;
}