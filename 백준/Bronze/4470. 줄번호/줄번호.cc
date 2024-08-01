#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	
	int n = 0;
	cin >> n;
	cin.ignore();

	string s;
	for (int i = 1; i <= n; ++i) {
		getline(cin, s);
		cout << i << ". " << s << "\n";
	}

	return 0;
}