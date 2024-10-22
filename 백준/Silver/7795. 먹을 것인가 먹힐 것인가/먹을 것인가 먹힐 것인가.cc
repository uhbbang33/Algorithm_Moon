#include <iostream>
#include <algorithm>
using namespace std;

int A[20001]{};
int B[20001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		for (int i = 0; i < n; ++i) 
			cin >> A[i];
		for (int i = 0; i < m; ++i)
			cin >> B[i];

		sort(B, B + m);
		
		int result = 0;

		for (int i = 0; i < n; ++i) {
			int start = 0, end = m - 1;
			while (start <= end) {
				int mid = (start + end) / 2;
				
				if (B[mid] < A[i]) 
					start = mid + 1;
				else
					end = mid - 1;
			}
			result += start;
		}
		cout << result << "\n";
	}

	return 0;
}