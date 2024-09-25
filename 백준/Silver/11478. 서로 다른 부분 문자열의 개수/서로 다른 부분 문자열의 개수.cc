#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	set<string> mySet;

	for (int i = 0; i < s.length(); ++i) {
		string tempStr = "";
		for (int j = i; j < s.length(); ++j) {
			tempStr += s[j];
			mySet.insert(tempStr);
		}
	}

	cout << mySet.size();

	return 0;
}