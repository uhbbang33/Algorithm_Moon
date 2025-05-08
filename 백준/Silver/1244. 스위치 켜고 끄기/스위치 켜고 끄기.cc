#include <iostream>
using namespace std;

bool arr[101]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	int m;
	cin >> m;

	while (m--) {
		int a, b;
		cin >> a >> b;

		if (a == 1) 
			for (int i = b; i <= n; i += b)
				arr[i] = !arr[i];
		else {
			arr[b] = !arr[b];
			
			int cur = 1;
			while (b - cur > 0 && b + cur <= n)
			{
				if (arr[b + cur] == arr[b - cur]) {
					arr[b + cur] = !arr[b + cur];
					arr[b - cur] = !arr[b - cur];
				}
				else
					break;

				++cur;
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << arr[i] << " ";
		if (i % 20 == 0)
			cout << "\n";
	}

	return 0;
}