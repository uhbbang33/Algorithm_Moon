#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	string s;
	
	while (t--) {
		cin >> s;

		list<char> l;
		auto cursor = l.begin();

		for (char c : s) {
			if (c == '<') {
				if (cursor != l.begin())
					--cursor;
			}
			else if (c == '>') {
				if (cursor != l.end())
					++cursor;
			}
			else if (c == '-') {
				if (cursor != l.begin()) {
					auto temp = cursor;
					--temp;
					l.erase(temp);
				}
			}
			else {
				cursor = l.insert(cursor, c);
				++cursor;
			}
		}

		for (char c : l)
			cout << c;
		cout << "\n";
	}



	return 0;
}