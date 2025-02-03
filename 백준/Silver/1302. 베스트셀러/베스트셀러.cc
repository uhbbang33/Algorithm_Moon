#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	map<string, int> m;

	for (int i = 0; i < n; ++i) {
		string book;
		cin >> book;

		if (m.find(book) == m.end())
			m.insert({ book, 1 });
		else 
			++m[book];
	}

	int maxNum = 0;
	string result = "";

	for (auto i : m)
		if (maxNum < i.second) {
			maxNum = i.second;
			result = i.first;
		}

	cout << result;

	return 0;
}
