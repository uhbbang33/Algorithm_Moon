#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s = "";
	string result = "";
    
	getline(cin, s);
	while (s != "END") {
		result = "";
		for (int i = s.length() - 1; i >= 0; --i)
		{
			result += s[i];
		}
		cout << result << endl;
		getline(cin, s);
	}

	return 0;
}