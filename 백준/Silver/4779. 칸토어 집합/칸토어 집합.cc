#include <iostream>
#include <math.h>
using namespace std;

void Func(string& s, int start, int end, int size) {
	if (size < 1)
		return;

	for (int i = start + size; i <= end - size; ++i)
		s[i] = ' ';

	int newSize = size / 3;
	Func(s, start, start + size - 1, newSize);
	Func(s, end - size + 1, end, newSize);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = -1;
	while (cin >> n) {
		string s;
		int len = pow(3, n);

		for (int i = 0; i < len; ++i)
			s += '-';

		Func(s, 0, len - 1, len / 3);
		cout << s << "\n";
	}

	return 0;
}