#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	map<string, bool> m;
	m.insert({ "ChongChong", true });
	int result = 1;

	for (int i = 0; i < n; ++i) {
		string s1, s2;
		cin >> s1 >> s2;

		if (m.find(s1) != m.end() && m.find(s2) == m.end()) {
			m.insert({ s2, true });
			++result;
		}
		else if (m.find(s1) == m.end() && m.find(s2) != m.end()) {
			m.insert({ s1, true });
			++result;
		}
	}

	cout << result;

	return 0;
}