#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int v;
	cin >> v;

	int a = 0, b = 0;
	for (int i = 0; i < v; ++i) {
		char c;
		cin >> c;
		if (c == 'A')
			++a;
		else
			++b;
	}

	if (a > b)
		cout << "A";
	else if (a < b)
		cout << "B";
	else
		cout << "Tie";

	return 0;
}
