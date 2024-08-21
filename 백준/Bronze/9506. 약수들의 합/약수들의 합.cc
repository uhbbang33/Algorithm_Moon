#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;
	while (n != -1) {
		
		queue<int> q;
		int sum = 0;
		for (int i = 1; i < n; ++i) {
			if (n % i == 0) {
				q.push(i);
				sum += i;
			}
		}

		if (sum == n) {
			cout << n << " = ";
			while (!q.empty()) {
				cout << q.front();
				q.pop();

				if (!q.empty()) cout << " + ";
			}
			cout << "\n";
		}
		else
			cout << n << " is NOT perfect." << "\n";

		cin >> n;
	}


	return 0;
}