#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	while (n--) {
		string s;
		cin >> s;

		if (s.length() >= 6 && s.length() <= 9)
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}