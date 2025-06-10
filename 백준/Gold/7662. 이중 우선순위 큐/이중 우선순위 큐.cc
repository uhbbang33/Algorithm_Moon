#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int k;
		cin >> k;

		multiset<int, less<int>> ms;

		while (k--) {
			char c; // I: 삽입, D: 삭제
			int n; // D일때 1: 최댓값, -1: 최솟값 

			cin >> c >> n;

			if (c == 'I') {
				ms.insert(n);
			}
			else if (!ms.empty()) {
				if (n == 1)
					ms.erase(--ms.end());
				else if (n == -1)
					ms.erase(ms.begin());
			}
		}

		if (ms.empty())
			cout << "EMPTY\n";
		else {
			cout << *(--ms.end()) << " ";
			cout << *ms.begin() << "\n";
		}
	}

	return 0;
}