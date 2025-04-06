#include <iostream>
#include <vector>
using namespace std;

int dp[1001][1001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s1, s2;
	cin >> s1 >> s2;

	for (int i = 1; i <= s1.length(); ++i) {
		for (int j = 1; j <= s2.length(); ++j) {
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	vector<char> v;

	int n = s1.length();
	int m = s2.length();

	while (n != 0 && m != 0) {
		if (dp[n][m] == dp[n - 1][m])
			--n;
		else if (dp[n][m] == dp[n][m - 1])
			--m;
		else {
			v.push_back(s1[n - 1]);
			--n;
			--m;
		}
	}

	cout << v.size() << "\n";
	for (int i = v.size() - 1; i >= 0; --i)
		cout << v[i];

	return 0;
}