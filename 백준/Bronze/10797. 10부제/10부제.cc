#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	cin >> num;

	int result = 0;
	for (int i = 0; i < 5; ++i) {
		int car;
		cin >> car;
		
		if (car % 10 == num)
			++result;
	}

	cout << result;

	return 0;
}