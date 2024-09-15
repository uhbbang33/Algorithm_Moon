#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	float result = 0;
	int totalCredit = 0;
	for (int i = 0; i < 20; ++i) {
		string s;
		cin >> s;

		float credit;
		cin >> credit;
		cin >> s;
		if (s == "P")
			continue;

		float score = 0;
		switch (s[0])
		{
		case 'A':
			score = 4.0f;
			break;
		case 'B':
			score = 3.0f;
			break;
		case 'C':
			score = 2.0f;
			break;
		case 'D':
			score = 1.0f;
			break;
		case 'F':
			score = 0.0f;
			break;
		default:
			break;
		}
		if (s[1] == '+')
			score += 0.5f;

		result += credit * score;
		totalCredit += credit;
	}

	cout << fixed;
	cout.precision(6);
	cout << result / totalCredit;

	return 0;
}