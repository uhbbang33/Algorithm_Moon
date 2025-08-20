#include <iostream>
using namespace std;

int arr[101]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		arr[i] = i;

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		
		int tempArr[101]{};
		tempArr[a] = arr[c];

		int cnt = a;
		for (int j = c + 1; j <= b; ++j) 
			tempArr[++cnt] = arr[j];
		for (int j = a; j <= c; ++j) 
			tempArr[++cnt] = arr[j];

		for (int i = a; i <= b; ++i)
			arr[i] = tempArr[i];
	}

	for (int i = 1; i <= n; ++i)
		cout << arr[i] << " ";

	return 0;
}