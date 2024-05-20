#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	map<string, double> m;
	string s = " ";
	int treeCount = 0;

	while (1) {
		getline(cin, s);

		if (cin.eof())
			break;

		++m[s];
		/*if (m.find(s) != m.end())
			++m.find(s)->second;
		else
			m.insert({ s, 1 });*/

		++treeCount;
	}

	cout << fixed;
	cout.precision(4);

	for (auto& tree : m)
		cout << tree.first << " " << tree.second / treeCount * 100 << "\n";
	
	return 0;
}