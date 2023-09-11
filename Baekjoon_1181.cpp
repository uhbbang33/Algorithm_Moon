#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	vector<string> v;

	for (int i = 0; i < n; ++i) {
		string s = "";
		cin >> s;

		v.push_back(s);
	}

	sort(v.begin(), v.end(), [&v](string a, string b) {
		if (a.length() == b.length())
			return a < b;
		else
			return a.length() < b.length();
		});

	v.erase(unique(v.begin(), v.end()), v.end());

	for (string s : v)
		cout << s << '\n';

	return 0;
}