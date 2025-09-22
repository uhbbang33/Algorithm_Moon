#include <iostream>
using namespace std;

int cnt[27]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		string name;
		cin >> name;

		++cnt[name[0] - 'a'];
	}

	string result = "";
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] >= 5)
			result += 'a' + i;
	}

	if (result == "")
		cout << "PREDAJA";
	else
		cout << result;

	return 0;
}