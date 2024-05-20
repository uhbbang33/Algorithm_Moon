#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v;
	v.push_back(0);
	v.push_back(1);

	int n = 0;
	cin >> n;
	
	for (int i = 2; i <= n; ++i)
		v.push_back(v[i - 1] + v[i - 2]);

	cout << v[n];

	return 0;
}