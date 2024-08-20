#include <iostream>
using namespace std;

bool IsPrime(int num) {
	for (int i = 2; i * i <= num; ++i) {
		if (num % i == 0)
			return false;
	}
	return true;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = -1;
	while (1) {
		cin >> n;
		if (n == 0)
			break;

		int cnt = 0;
		for (int i = n + 1; i <= n * 2; ++i)
			if (IsPrime(i))
				++cnt;

		cout << cnt << "\n";
	}

	return 0;
}