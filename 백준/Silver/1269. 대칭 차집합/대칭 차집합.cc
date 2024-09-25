#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;

	map<int, int> m;

	for (int i = 0; i < a + b; ++i) {
		int x;
		cin >> x;
		++m[x];
	}

	int result = 0;
	for (auto iter : m) {
		if (iter.second == 1)
			++result;
	}
	cout << result;


	return 0;
}