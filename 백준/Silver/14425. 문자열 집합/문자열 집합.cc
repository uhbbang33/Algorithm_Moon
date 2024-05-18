#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0, m = 0;
	cin >> n >> m;

	string s;
	map<string, int> myMap;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		myMap.insert(make_pair(s, i));
	}
	
	int result = 0;
	for (int i = 0; i < m; ++i) {
		cin >> s;
		if (myMap.find(s) != myMap.end())
			++result;
	}

	cout << result;

	return 0;
}