#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	set<string> s;
	while (next_permutation(v.begin(), v.end())) {
		string str;
		for (int i = 0; i < k; ++i)
			str += to_string(v[i]);
		s.insert(str);
	}

	cout << s.size();

	return 0;
}
