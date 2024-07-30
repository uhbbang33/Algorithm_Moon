#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int k = 0;
	cin >> k;

	vector<int> v;
	
	int num = 0;
	for (int i = 0; i < k; ++i) {
		cin >> num;
		if (num == 0 && !v.empty())
			v.pop_back();
		else
			v.push_back(num);
	}

	int result = 0;
	for (int i = 0; i < v.size(); ++i)
		result += v[i];

	cout << result;

	return 0;
}