#include <iostream>
#include <regex>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		regex pattern("(100+1+|01)+");
		if (regex_match(s, pattern))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	
	return 0;
}