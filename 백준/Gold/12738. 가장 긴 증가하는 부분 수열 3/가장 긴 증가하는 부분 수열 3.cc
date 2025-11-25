#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		
		if (arr.empty() || arr.back() < a)
			arr.push_back(a);
		else
			*lower_bound(arr.begin(), arr.end(), a) = a;
	}
	cout << arr.size();

	return 0;
}