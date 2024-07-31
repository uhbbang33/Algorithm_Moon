#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	map<int, int> m;

	string s = "";
	int num = 0;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		if (s == "all") {
			for (int j = 1; j <= 20; ++j)
				m[j] = j;

			continue;
		}
		else if (s == "empty") {
			for (int j = 1; j <= 20; ++j)
				m[j] = 0;

			continue;
		}

		cin >> num;

		if (s == "add")
			++m[num];
		else if (s == "remove")
			m[num] = 0;
		else if (s == "check") {
			if (m[num] > 0)
				cout << "1" << "\n";
			else
				cout << "0" << "\n";
		}
		else if (s == "toggle") {
			if (m[num] == 0)
				++m[num];
			else
				m[num] = 0;
		}
	}

	return 0;
}