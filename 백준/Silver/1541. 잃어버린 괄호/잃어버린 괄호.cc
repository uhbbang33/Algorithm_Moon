#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;

	string tempNumStr = "";

	bool isMinus = false;

	int result = 0;
	int tempSum = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (isalnum(s[i]))
			tempNumStr += s[i];
		else {
			if (s[i] == '-') {
				tempSum += stoi(tempNumStr);
				tempNumStr = "";

				if (isMinus) result -= tempSum;
				else result += tempSum;

				tempSum = 0;
				isMinus = true;
			}
			else {
				tempSum += stoi(tempNumStr);
				tempNumStr = "";
			}
		}
	}
	tempSum += stoi(tempNumStr);

	if (isMinus) result -= tempSum;
	else result += tempSum;

	cout << result;

	return 0;
}