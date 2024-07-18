#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vertex;

int BinarySearch(int start, int end, int targetStart, int targetEnd) {
	int first = lower_bound(vertex.begin(), vertex.end(), targetStart) - vertex.begin();
	int last = upper_bound(vertex.begin(), vertex.end(), targetEnd) - vertex.begin();

	return last - first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vertex.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> vertex[i];
	sort(vertex.begin(), vertex.end());

	int startVt, endVt;
	for (int i = 0; i < m; ++i) {
		cin >> startVt >> endVt;
		
		cout << BinarySearch(0, n-1, startVt, endVt) << "\n";
	}

	return 0;
}