#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	w -= x;
	h -= y;

	cout <<min(min(w, h), min(x, y));

	return 0;
}