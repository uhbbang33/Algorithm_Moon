#include <iostream>
#include <vector>
using namespace std;

int A[101][101]{};
int B[101][101]{};
int C[101][101]{};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j)
			cin >> A[i][j];

	int bm, k;
	cin >> bm >> k;

	for (int i = 0; i < bm; ++i)
		for (int j = 0; j < k; ++j)
			cin >> B[i][j];

	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			for (int l = 0; l < m; ++l) 
				C[i][j] += A[i][l] * B[l][j];
			
			cout << C[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}