#include <iostream>
using namespace std;

int arr[26][200001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); ++i) {
		if (i != 0)
			for (int j = 0; j < 26; ++j)
				arr[j][i] = arr[j][i - 1];

		int cur = s[i] - 'a';
		++arr[cur][i];
	}

	int q;
	cin >> q;

	while (q--) {
		char a;
		int l, r;
		cin >> a >> l >> r;

		int cur = a - 'a';
		
		cout << arr[cur][r] - arr[cur][l - 1] << "\n";
	}

	return 0;
}