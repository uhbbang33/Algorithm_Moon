#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;

	int cnt = 0;
	for (char c : s)
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			++cnt;
	cout << cnt;
	
	return 0;
}