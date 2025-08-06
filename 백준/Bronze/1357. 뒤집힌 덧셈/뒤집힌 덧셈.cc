#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string x, y;
	cin >> x >> y;

	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());

	int sum = stoi(x) + stoi(y);
	
	string s = to_string(sum);
	for (int i = s.length()-1; i >= 0; --i){
		if (s[i] == '0')
			s.pop_back();
		else
			break;
	}

	reverse(s.begin(), s.end());

	cout << s;

	return 0;
}