#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	
	int a = 0, b= 0, c= 0;
	while (t >= 300) {
		t -= 300;
		++a;
	}
	while (t >= 60) {
		t -= 60;
		++b;
	}
	while (t >= 10) {
		t -= 10;
		++c;
	}

	if (t == 0)
		cout << a << " " << b << " " << c;
	else
		cout << "-1";

	return 0;
}