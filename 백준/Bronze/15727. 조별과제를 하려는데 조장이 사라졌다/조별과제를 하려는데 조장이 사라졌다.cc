#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int l;
	cin >> l;
	
	int result = l / 5;
	if (l % 5 != 0)
		++result;

	cout << result;


	return 0;
}