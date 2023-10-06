#include <iostream>
#include <queue>
using namespace std;

// https://www.acmicpc.net/problem/10845

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	
	queue<int> q;

	string str = "";
	int num = 0;
	for (int i = 0; i < n; ++i) {
		cin >> str;

		if (str == "push") {
			cin >> num;
			q.push(num);
		}
		else if (str == "pop") {
			if (q.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << q.front() << '\n';
			q.pop();
		}
		else if (str == "size")
			cout << q.size() << '\n';
		else if (str == "empty")
			if (q.empty()) cout << "1\n";
			else cout << "0\n";
		else if (str == "front") {
			if (q.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << q.front() << '\n';
		}
		else if (str == "back") {
			if (q.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << q.back() << '\n';
		}
	}

	return 0;
}