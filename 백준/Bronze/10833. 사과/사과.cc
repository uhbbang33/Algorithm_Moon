#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int result = 0;
	for (int i = 0; i < n; ++i) {
		int student, apple;
		cin >> student >> apple;

		result += apple% student;
	}

	cout << result;

	return 0;
}