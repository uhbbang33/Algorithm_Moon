#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	map<string, string, greater<>> m;

	for (int i = 0; i < n; ++i) {
		string name, log;
		cin >> name >> log;
		m[name] = log;
	}

	for (const auto& p : m)
		if (p.second != "leave")
			cout << p.first << "\n";

	return 0;
}