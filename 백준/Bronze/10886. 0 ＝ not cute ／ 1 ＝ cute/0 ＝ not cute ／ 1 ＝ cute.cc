#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int cuteAnswer = 0;
	for (int i = 0; i < n; ++i) {
		bool isCute;
		cin >> isCute;

		if (isCute)
			++cuteAnswer;
	}

	if (n / 2 < cuteAnswer)
		cout << "Junhee is cute!";
	else
		cout << "Junhee is not cute!";

	return 0;
}
