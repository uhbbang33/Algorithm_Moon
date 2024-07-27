#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	int num = 665;
	int cnt = 0;
	while (n != cnt) {
		++num;

		string temp = to_string(num);
		if (temp.find("666") != string::npos)
			++cnt;
	}
	cout << num;

	return 0;
}