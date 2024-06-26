#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), greater<>());

	int result = 0;
	for (int i = 0; i < n; ++i) {
		if (i % 3 == 2)
			continue;
		
		result += v[i];
	}
	cout << result;

	return 0;
}