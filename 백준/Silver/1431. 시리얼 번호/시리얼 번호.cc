#include <iostream>
#include <algorithm>
using namespace std;

string arr[51]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr, arr + n, [](string a, string b) -> bool {
		if (a.length() != b.length())
			return a.length() < b.length();

		int aNum = 0, bNum = 0;
		for (char c : a)
			if (isdigit(c))
				aNum += c - '0';

		for (char c : b)
			if (isdigit(c))
				bNum += c - '0';

		if (aNum != bNum)
			return aNum < bNum;

		return a < b;
		});


	for (int i = 0; i < n; ++i)
		cout << arr[i] << "\n";

	return 0;
}