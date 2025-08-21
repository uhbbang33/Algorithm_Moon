#include <iostream>
using namespace std;

int room[200001]{};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int k, s, e;
		cin >> k >> s >> e;

		if (room[k] <= s) {
			room[k] = e;
			cout << "YES\n";
		}
		else
			cout << "NO\n";
	}

	return 0;
}