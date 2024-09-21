#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	
	vector<int> v;
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			v.push_back(i);
			if (i * i != n)
				v.push_back(n / i);
		}
	}
	v.push_back(n);

	sort(v.begin(), v.end());

	if (v.size() > k)
		cout << v[k - 1];
	else
		cout << "0";

	return 0;
}