#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int result = 0;
	string num = "";
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] != ',')
			num += s[i];
		else {
			result += stoi(num);
			num = "";
		}
	}

	result += stoi(num);
	cout << result;

	return 0;
}