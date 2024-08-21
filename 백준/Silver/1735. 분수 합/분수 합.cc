#include <iostream>
using namespace std;

int GCD(int a, int b) {

	while (b != 0) {
		int r = b;
		b = a% b;
		a = r;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int s[2], m[2];
	cin >> s[0] >> m[0] >> s[1] >> m[1];

	s[0] = m[1] * s[0] + m[0] * s[1];
	m[0] = m[0] * m[1];
	
	int temp = (s[0] > m[0]) ? GCD(s[0], m[0]) : GCD(m[0], s[0]);

	s[0] /= temp;
	m[0] /= temp;

	cout << s[0] << " " << m[0];

	return 0;
}