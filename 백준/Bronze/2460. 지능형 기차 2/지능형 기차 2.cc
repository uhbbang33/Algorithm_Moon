#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int cur = 0;
	int maxResult = 0;

	for (int i = 0; i < 10; ++i) {
		int out,in;
		cin >> out >> in;
		
		cur -= out;
		cur += in;
		
		maxResult = max(cur, maxResult);
	}

	cout << maxResult;

	return 0;
}
