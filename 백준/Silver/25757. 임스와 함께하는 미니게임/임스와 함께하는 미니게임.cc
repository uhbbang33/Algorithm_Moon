#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	char game;
	cin >> game;

	int requireNum = 0;
	if (game == 'Y')
		requireNum = 1;
	else if (game == 'F')
		requireNum = 2;
	else requireNum = 3;

	set<string> s;

	for (int i = 0; i < n; ++i) {
		string user;
		cin >> user;

		s.insert(user);
	}

	cout << s.size() / requireNum;


	return 0;
}