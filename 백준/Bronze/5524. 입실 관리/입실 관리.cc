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

		for (char& c : s) 
			if (c <= 'Z')
				c += 'a' - 'A';

		cout << s << "\n";
	}

	return 0;
}