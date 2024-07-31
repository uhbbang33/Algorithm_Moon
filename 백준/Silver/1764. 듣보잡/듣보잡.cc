#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	set<string> nameSet;
	vector<string> resultVec;

	string name;
	for (int i = 0; i < n; ++i) {
		cin >> name;
		nameSet.insert(name);
	}
	for (int i = 0; i < m; ++i) {
		cin >> name;

		if (nameSet.find(name) != nameSet.end())
			resultVec.push_back(name);
	}

	cout << resultVec.size() << "\n";
	sort(resultVec.begin(), resultVec.end());
	for (int i = 0; i < resultVec.size(); ++i)
		cout << resultVec[i] << "\n";

	return 0;
}