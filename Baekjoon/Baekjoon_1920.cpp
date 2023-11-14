#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	cin >> n;
	vector<int> A;

	int temp = 0;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		A.push_back(temp);
	}
	sort(A.begin(), A.end());
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		cout << binary_search(A.begin(), A.end(), temp) << '\n';
	}

	return 0;
}