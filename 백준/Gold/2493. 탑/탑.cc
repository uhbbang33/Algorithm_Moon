#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	stack<pair<int, int>> s; // 높이, 번호

	for (int i = 1; i <= n; ++i) {
		int curTop;
		cin >> curTop;

		while (!s.empty()
			&& s.top().first < curTop)
			s.pop();

		if (!s.empty())
			cout << s.top().second << " ";
		else
			cout << "0 ";

		s.push({ curTop, i });
	}

	
	return 0;
}
