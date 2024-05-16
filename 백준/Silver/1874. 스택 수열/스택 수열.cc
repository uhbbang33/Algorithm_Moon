#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;

	int num = 0;
	string result = "";

	stack<int> st;
	int maxNum = 0;
	st.push(0);
	
	for (int i = 0; i < n; ++i) {
		cin >> num;
		if (num > st.top() && num > maxNum) {
			for (int j = maxNum+1; j <= num; ++j) {
				st.push(j);
				result += '+';
			}
			maxNum = num;
		}
		if(num == st.top()) {
			st.pop();
			result += '-';
		}
		else {
			cout << "NO" << "\n";
			return 0;
		}
	}

	for (char c : result) {
		cout << c << "\n";
	}

	return 0;
}