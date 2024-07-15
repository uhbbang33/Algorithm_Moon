#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long s = 0;
	cin >> s;

	long long temp = 1;
	int cnt = 0;
	while (s != 0) {
		if (s > 2 * temp || s== temp) {
			s -= temp;
			++cnt;
		}
		++temp;
	}

	cout << cnt;
	return 0;
}