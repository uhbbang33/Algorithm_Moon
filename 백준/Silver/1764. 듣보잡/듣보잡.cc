#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	map<string, int> nameMap;
	vector<string> resultVec;

	string name;
	for (int i = 0; i < n; ++i) {
		cin >> name;
		++nameMap[name];
	}
	for (int i = 0; i < m; ++i) {
		cin >> name;

		if (nameMap[name] > 0) {
			resultVec.push_back(name);
		}
	}

	cout << resultVec.size() << "\n";
	sort(resultVec.begin(), resultVec.end());
	for (int i = 0; i < resultVec.size(); ++i)
		cout << resultVec[i] << "\n";

	return 0;
}