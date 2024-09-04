#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	cin >> n;

	stack<int> s;
	while (n != 0) {
		if (n % 2 == 1)
			s.push(1);
		else
			s.push(0);
		
		n /= 2;
	}
	
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}

	return 0;
}