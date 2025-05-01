#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	set<int> s;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;

		s.insert(a);
	}

	for (int a : s)
		cout << a << " ";

	return 0;
}