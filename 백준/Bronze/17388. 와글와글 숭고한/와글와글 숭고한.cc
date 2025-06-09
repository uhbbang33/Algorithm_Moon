#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int s, k, h;
	cin >> s >> k >> h;

	int m = min(s, min(k, h));

	if (s + k + h >= 100)
		cout << "OK";
	else if (m == s)
		cout << "Soongsil";
	else if (m == k)
		cout << "Korea";
	else cout << "Hanyang";

	return 0;
}