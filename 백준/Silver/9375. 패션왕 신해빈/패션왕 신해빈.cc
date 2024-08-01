#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 0;
	cin >> t;

	int n = 0;
	for (int i = 0; i < t; ++i) {
		cin >> n;

		unordered_map<string, int> m;
		string name, type;
		for (int j = 0; j < n; ++j) {
			cin >> name >> type;
			++m[type];
		}

		int result = 1;
		for (auto iter = m.begin(); iter != m.end(); ++iter)
			result *= (*iter).second + 1;

		cout << result-1 << "\n";
	}

	return 0;
}