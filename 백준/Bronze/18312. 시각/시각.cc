#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	int cnt = 0;
	int hour = 0;

	while (hour <= n) {
		if (hour % 10 == k || hour / 10 == k)
			cnt += 3600;
		else
			for (int i = 0; i < 60; ++i)
				if (i % 10 == k || i / 10 == k)
					cnt += 60;
				else
					for (int j = 0; j < 60; ++j)
						if (j % 10 == k || j / 10 == k)
							++cnt;
		++hour;
		if (hour == 24 && n != 23)
			hour = 0;
	}

	cout << cnt;

	return 0;
}