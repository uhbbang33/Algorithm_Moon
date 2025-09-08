#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;
	
	string maxA, maxB, minA, minB;
	for (char c : a) {
		if (c == '5')
			c = '6';
		maxA += c;

		if (c == '6')
			c = '5';
		minA += c;
	}
	for (char c : b) {
		if (c == '5')
			c = '6';
		maxB += c;

		if (c == '6')
			c = '5';
		minB += c;
	}

	cout << stoi(minA) + stoi(minB) << " ";
	cout << stoi(maxA) + stoi(maxB);

	return 0;
}