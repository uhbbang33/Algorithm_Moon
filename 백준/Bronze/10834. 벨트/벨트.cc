#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m;
	cin >> m;

	int prev = 0;
	int cnt = 0;

	for (int i = 0; i < m; ++i) {
		int a, b;
		bool isCross;
		cin >> a >> b >> isCross;
		
		if (isCross)
			++cnt;

		if (prev == 0) {
			prev = b;
			continue;
		}

		if (a < prev) 
			b *= prev / a;
		else if(a > prev) 
			b /= prev;

		prev = b;
	}

	if (cnt % 2 == 0)
		cout << "0 ";
	else
		cout << "1 ";

	cout << prev;

	return 0;
}