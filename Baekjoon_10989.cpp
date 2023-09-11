#include <iostream>
using namespace std;

int num[10001] = {};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		++num[a];
	}

	for (int i = 0; i < 10001; ++i) {
		while(num[i] > 0){
			cout << i << "\n";
			--num[i];
		}
	}

	return 0;
}
