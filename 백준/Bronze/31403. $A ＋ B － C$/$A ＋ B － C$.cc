#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int a, b, c;
	cin >> a >> b >> c;
	cout << a + b - c << "\n";
	string str1 = to_string(a) + to_string(b);
	a = stoi(str1);
	cout << a - c;

	return 0;
}