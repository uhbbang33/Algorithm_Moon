#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 0;
	cin >> t;

	string fst;
	int snd;
	for (int i = 0; i < t; ++i) {
		cin >> fst;
		int firstNum = (fst[0] - 'A') + (fst[1] - '0');

		cin >> snd;
		snd -= 1;
		int secondNum = snd/ 8 + snd % 8;

		if (firstNum % 2 != secondNum % 2)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}


	return 0;
}