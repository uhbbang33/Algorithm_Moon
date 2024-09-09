#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s, bomb;
	cin >> s >> bomb;

	int bombLength = bomb.length();

	string result = "";

	for (char c : s) {
		result.push_back(c);

		if (result.size() >= bombLength) {
			bool isBomb = true;

			for (int i = 0; i < bombLength; ++i) {
				if (result[result.size() - bombLength + i] != bomb[i]){
					isBomb = false;
					break;
				}
			}

			if (isBomb)
				for (int i = 0; i < bombLength; ++i)
					result.pop_back();
		}
	}

	if (result == "")
		cout << "FRULA";
	else
		cout << result;

	return 0;
}