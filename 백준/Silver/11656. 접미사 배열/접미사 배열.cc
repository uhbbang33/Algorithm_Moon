#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	priority_queue<string,vector<string>, greater<>> pq;

	for (int i = 0; i < s.length(); ++i) {
		string curStr = "";
		for (int j = i; j < s.length(); ++j)
			curStr += s[j];

		pq.push(curStr);
	}

	while (!pq.empty()) {
		cout << pq.top() << "\n";
		pq.pop();
	}


	return 0;
}