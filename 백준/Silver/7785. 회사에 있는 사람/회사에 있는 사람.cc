#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	map<string, int, greater<>> m;

	for (int i = 0; i < n; ++i) {
		string name, log;
		cin >> name >> log;
		if (log == "enter")
			m[name] = 1;
		else
			m[name] = 0;
	}

	for (const auto& p : m)
		if (p.second == 1)
			cout << p.first << "\n";

	return 0;
}