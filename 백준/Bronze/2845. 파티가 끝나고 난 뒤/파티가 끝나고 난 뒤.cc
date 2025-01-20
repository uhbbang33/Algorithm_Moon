#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int l, p;
	cin >> l >> p;
	int correct = l * p;

	for (int i = 0; i < 5; ++i) {
		int news;
		cin >> news;

		cout << news - correct << " ";
	}


	return 0;
}
