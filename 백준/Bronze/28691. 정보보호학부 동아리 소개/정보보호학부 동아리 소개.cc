#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	char c;
	cin >> c;

	if (c == 'M') cout << "MatKor";
	if (c == 'W') cout << "WiCys";
	if (c == 'C') cout << "CyKor";
	if (c == 'A') cout << "AlKor";
	if (c == '$') cout << "$clear";

	return 0;
}