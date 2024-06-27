#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n = 0;
	cin >> n;

	char c = ' ';
	char temp = ' ';
	int result = 0;
	for (int i = 0; i < n; ++i) {
		cin >> c;
		if (c != temp)
			++result;
		temp = c;
	}

	cout << result / 2 + 1;

	return 0;
}