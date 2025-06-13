#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	int n, d;
	while (t--) {
		cin >> n >> d;

		int v, f, c;
		int result = 0;

		while (n--) {
			cin >> v >> f >> c;

			if(d * c <= v * f)
				++result;
		}
		cout << result << "\n";
	}

	return 0;
}