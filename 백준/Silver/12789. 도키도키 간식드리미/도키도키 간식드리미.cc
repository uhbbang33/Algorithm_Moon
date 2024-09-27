#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	stack<int> s;
	int curNum = 1;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;

		if (curNum == num) {
			++curNum;
		}
		else if (!s.empty() && s.top() < num)
		{
			cout << "Sad";
			return 0;
		}
		else
			s.push(num);

		while (!s.empty() && s.top() == curNum) {
			s.pop();
			++curNum;
		}
	}
	cout << "Nice";

	return 0;
}