#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	set<string> mySet;
	int result = 0;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		
		if (s == "ENTER") {
			result += mySet.size();
			mySet.clear();
		}
		else
			mySet.insert(s);
	}
	result += mySet.size();

	cout << result;

	return 0;
}