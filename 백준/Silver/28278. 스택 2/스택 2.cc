#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	stack<int> s;

	while (n--) {
		int a;
		cin >> a;
		switch (a) {
		case 1:
			int x;
			cin >> x;
			s.push(x);
			break;
		case 2:
			if (s.empty())
				cout << "-1" << "\n";
			else {
				cout << s.top() << "\n";
				s.pop();
			}
			break;
		case 3:
			cout << s.size() << "\n";
			break;
		case 4:
			if (s.empty())
				cout << "1" << "\n";
			else 
				cout << "0" << "\n";
			break;
		case 5:
			if (s.empty())
				cout << "-1" << "\n";
			else
				cout << s.top() << "\n";
			break;
		default:
			break;
		}
	}

	return 0;
}