#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	bool breakButton[10]{};
	for (int i = 0; i < m; ++i) {
		int button;
		cin >> button;
		breakButton[button] = true;
	}

	// current Channel = 100
	int result = abs(100 - n);

	for (int i = 0; i <= 1000000; ++i) {
		string channel = to_string(i);
		bool isValid = true;

		for (char c : channel) {
			if (breakButton[c - '0']) {
				isValid = false;
				break;
			}
		}

		if (isValid) {
			int dist = abs(n - i) + channel.length();
			result = min(result, dist);
		}
	}

	cout << result;

	return 0;
}