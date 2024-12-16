#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	while (1) {
		string s;
		cin >> s;
		
		if (s == "0")
			break;

		int result = 1;
		for (char c : s) {
			if (c == '1')
				result += 3;
			else if (c == '0')
				result += 5;
			else
				result += 4;
		}

		cout << result << "\n";
	}

	return 0;
}