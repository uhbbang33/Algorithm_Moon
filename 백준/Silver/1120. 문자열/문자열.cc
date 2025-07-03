#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;

	int result = 51;
	for (int i = 0; i < b.length() - a.length() + 1; ++i) {
		int nonSameNum = 0;
		for (int j = 0; j < a.length(); ++j) {
			if (b[i + j] != a[j])
				++nonSameNum;
		}

		result = min(result, nonSameNum);
	}

	cout << result;

	return 0;
}