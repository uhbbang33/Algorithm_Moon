#include <iostream>
#include <algorithm>
using namespace std;

int l, c;
char arr[16]{};
bool visited[16]{};

void MakeStr(int startNum, string s) {
	if (s.length() == l) {
		int cnt = 0;
		for (int i = 0; i < l; ++i)
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
				++cnt;

		if (cnt >= 1 && cnt <= l - 2)
			cout << s << "\n";

		return;
	}

	for (int i = startNum + 1; i < c; ++i) {
		if (!visited[i]) {
			visited[i] = true;
			s += arr[i];

			MakeStr(i, s);

			s.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> l >> c;

	for (int i = 0; i < c; ++i)
		cin >> arr[i];
	sort(arr, arr + c);

	for (int i = 0; i <= c - l; ++i) {
		visited[i] = true;
		string s = "";
		s += arr[i];

		MakeStr(i, s);
	}

	return 0;
}