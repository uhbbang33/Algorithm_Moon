#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	string s = "";
	int result = 0;
	cin >> s;
	for (char c : s) {
		result += c - '0';
	}
	cout << result;
	return 0;
}