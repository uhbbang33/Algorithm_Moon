#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	int h;
	int max = 0;
	stack<int> s;

	for (int i = 0; i < n; ++i) {
		cin >> h;
		s.push(h);
	}

	int result = 0;
	while(!s.empty()){
		if (s.top() > max) {
			++result;
			max = s.top();
		}
		s.pop();
	}
	
	cout << result;

	return 0;
}