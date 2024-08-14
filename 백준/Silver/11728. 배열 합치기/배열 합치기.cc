#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	vector<int> A(n);
	vector<int> B(m);
	for (int i = 0; i < n; ++i)
		cin >> A[i];
	for (int i = 0; i < m; ++i)
		cin >> B[i];

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int aPointer = 0, bPointer = 0;
	for (int i = 0; i < n + m; ++i) {
		if (A[aPointer] <= B[bPointer]) {
			cout << A[aPointer] << " ";
			++aPointer;
		}
		else if(A[aPointer] > B[bPointer]){
			cout << B[bPointer] << " ";
			++bPointer;
		}

		if (bPointer == m) {
			while (aPointer != n) {
				cout << A[aPointer] << " ";
				++aPointer;
			}
			break;
		}
		else if (aPointer == n) {
			while (bPointer != m) {
				cout << B[bPointer] << " ";
				++bPointer;
			}
			break;
		}
	}

	return 0;
}