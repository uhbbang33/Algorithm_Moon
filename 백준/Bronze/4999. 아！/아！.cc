#include <iostream>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s1, s2;
	cin >> s1 >> s2;
	if (s2.length() > s1.length())
		cout << "no";
	else
		cout << "go";

	return 0;
}