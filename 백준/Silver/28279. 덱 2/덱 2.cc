#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	deque<int> d;

	while (n--) {
		int a;
		cin >> a;

		int x;
		switch (a) {
		case 1:
			cin >> x;
			d.push_front(x);
			break;
		case 2:
			cin >> x;
			d.push_back (x);
			break;
		case 3:
			if (d.empty())
				cout << "-1" << "\n";
			else {
				cout << d.front() << "\n";
				d.pop_front();
			}
			break;
		case 4:
			if (d.empty())
				cout << "-1" << "\n";
			else {
				cout << d.back() << "\n";
				d.pop_back();
			}
			break;
		case 5:
			cout << d.size() << "\n";
			break;
		case 6:
			if (d.empty())
				cout << "1" << "\n";
			else
				cout << "0" << "\n";
			break;
		case 7:
			if (d.empty())
				cout << "-1" << "\n";
			else
				cout << d.front() << "\n";
			break;
		case 8:
			if (d.empty())
				cout << "-1" << "\n";
			else
				cout << d.back() << "\n";
			break;
		default:
			break;
		}
	}


	return 0;
}