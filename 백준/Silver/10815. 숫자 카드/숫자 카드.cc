#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n;

	vector<int> cards(n);
	for (int i = 0; i < n; ++i)
		cin >> cards[i];
	sort(cards.begin(), cards.end());
	
	cin >> m;

	vector<int> check(m);
	for (int i = 0; i < m; ++i) {
		cin >> check[i];
		cout << binary_search(cards.begin(), cards.end(), check[i]) << " ";
	}

	return 0;
}