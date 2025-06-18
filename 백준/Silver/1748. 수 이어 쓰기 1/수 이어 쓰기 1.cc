#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int result = 0;

	for (int i = 0; i < s.length() - 1; ++i)
		result += 9 * pow(10, i) * (i + 1);

	result += s.length() * (stoi(s) - pow(10, s.length() - 1) + 1);

	cout << result;

	return 0;
}