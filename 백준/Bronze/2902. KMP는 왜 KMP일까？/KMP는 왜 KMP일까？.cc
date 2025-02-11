#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string input;
	cin >> input;

	string result = "";
	result += input[0];

	bool next = false;

	for (char c : input) {
		if (next) {
			result += c;
			next = false;
		}

		if (c == '-')
			next = true;
	}

	cout << result;

	return 0;
}
